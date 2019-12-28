#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "ll.h"

transac *new_transaction(char *dsc, float a, time_t dt)
{
    transac *new = malloc(sizeof(transac));
    new -> desc = calloc(strlen(dsc) + 1, sizeof(char));
    strcpy(new -> desc, dsc);
    new -> date = dt;
    new -> amt = a;
    new -> next = NULL;
    return new;
}

time_t time_from_ints(int day, int month, int year, int hour, int min)
{
    time_t ltime = time(NULL);
    struct tm d = *localtime(&ltime);
    d.tm_mon = month - 1;
    d.tm_mday = day;
    d.tm_hour = hour - 1;
    d.tm_min = min;
    d.tm_year = year - 1900;
    return mktime(&d);
}

transac *transaction_from_string(char *s)
// assuming a properly-formatted string
// https://stackoverflow.com/a/4693942
{
    char data[100];
    strcpy(data, s);

    int year, month, day, hour, min;
    float amt;
    char *dsc = calloc(50, sizeof(char));

    sscanf(data, "%d/%d/%d %d:%d,%[^\t\n,],%f",
           &month, &day, &year, &hour, &min,
           dsc, &amt);

    time_t tme = time_from_ints(day, month, year, hour, min);    

    transac *t = new_transaction(dsc, amt, tme);
    free(dsc);
    return t;
}

void print_transaction(transac *t)
{
    time_t time = t -> date;
    struct tm d = *localtime(&time); 
    printf("Transaction at %02d/%02d/%04d at %02d:%02d\n",
           d.tm_mon + 1, d.tm_mday, d.tm_year + 1900, d.tm_hour, d.tm_min);
    printf(" -- description: %s\n", t -> desc);
    printf(" -- amount: %.2f\n", t -> amt);
}

void free_transac_list(transac *t)
{
    if (t == NULL)
        return;
    free_transac_list(t -> next);
    free(t);
}

ledger *blank_ledger(time_t start, float monthly, float weekly)
{
    ledger *l = malloc(sizeof(ledger));
    l -> head = NULL;
    l -> tail = NULL;
    l -> size = 0;
    l -> start_time = start;
    l -> monthly_budget = monthly;
    l -> weekly_budget = weekly;
    return l;
}

void free_ledger(ledger *l)
{
    free_transac_list(l -> head);
    free(l);
}

void append_transac(ledger *l, transac *t)
{
    if (l -> head == NULL) {
        l -> head = t;
        l -> tail = t;
        l -> size++;
    } else {
        l -> tail -> next = t;
        l -> tail = t;
        l -> size++;
    }
}

ledger *ledger_from_file(time_t start, float monthly, float weekly, FILE *f)
// https://stackoverflow.com/a/3501681
{
    ledger *l = blank_ledger(start, monthly, weekly);
    if (f != NULL) {
        ssize_t read;
        size_t len = 0;
        char *line = NULL;
        transac *t;
        while ((read = getline(&line, &len, f)) != -1) {
            append_transac(l, transaction_from_string(line));
        }
    }
    return l;
}

void print_ledger(ledger *l)
{
    transac *curr = l -> head;
    int counter = 0;
    printf("=====TRANSACTION HISTORY=====\n");
    while (curr) {
        ++counter;
        print_transaction(curr);
        if (counter != l -> size) {
            printf("=============================\n");
        }
        curr = curr -> next;
    }
}
