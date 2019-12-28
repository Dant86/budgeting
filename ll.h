#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#ifndef _LL_H_
#define _LL_H_

typedef struct nd
{
    time_t date;
    char *desc;
    float amt;
    struct nd *next;
} transac;

typedef struct ll
{
    time_t start_time;
    transac *head;
    transac *tail;
    float monthly_budget;
    float weekly_budget;
    int size;
} ledger;

transac *new_transaction(char *dsc, float a, time_t dt);

void print_transaction(transac *t);

void free_transac_list(transac *t);

time_t time_from_ints(int day, int month, int year, int hour, int min);

transac *transaction_from_string(char *s);

ledger *blank_ledger(time_t start, float monthly, float weekly);

void append_transac(ledger *l, transac *t);

ledger *ledger_from_file(time_t start, float monthly, float weekly, FILE *f);

void print_ledger(ledger *l);

void free_ledger(ledger *l);

#endif