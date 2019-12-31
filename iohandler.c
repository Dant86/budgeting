#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "ll.h"
#include "iohandler.h"

/*
    Input options:
        view
        [deposit/withdraw] [amount] "[description]"
        save
        QUIT
*/

void parse_cmd(char *input, ledger *l)
{
    float amt;
    char desc[100];
    char depwith[10];
    if (input == NULL) {
        return;
    }
    if (!strcmp(input, "view")) {
        print_ledger(l);
        return;
    }
    if (!strcmp(input, "save")) {
        return; // TODO: create ledger save function
    }
    if (!strcmp(input, "exit")) {
        printf("Quitting...\n");
        exit(0);
    }
    transac *t;
    char c;
    if (sscanf(input, "%s %f \"%[^\t\n,\"]\"", depwith, &amt, desc) == 2) {
        printf("%s\n", input);
        if (!strcmp(depwith, "deposit")) {
            printf("%s\n", input);
            t = new_transaction(desc, amt, time(NULL), 1);
            append_transac(l, t);
        }
        if (!strcmp(depwith, "withdraw")) {
            t = new_transaction(desc, amt, time(NULL), 0);
            append_transac(l, t);
        }
    }
    return;
}