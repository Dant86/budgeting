#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "ll.h"

#define MONTHLY_BUDGET 500
#define WEEKLY_BUDGET 100
#define DEFAULT_TIME time_from_ints(1, 1, 2019, 0, 0)

int find(char *needle, char **haystack, int n)
{
    for (int i = 0; i < n; i++) {
        if (!strcmp(haystack[i], needle)) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    /*
        COMMAND LINE ARGS:
            -f <TXT_FNAME> -> load an existing ledger
            -w <WEEKLY_BUDGET> -> set custom weekly budget
            -m <MONTHLY_BUDGET> -> set custom monthly budget
    */
    FILE *ledger_f = NULL;
    int ix;
    if ((ix = find("-f", argv, argc)) > 0)
        ledger_f = fopen(argv[ix + 1], "r+");
    ledger *l = ledger_from_file(DEFAULT_TIME, MONTHLY_BUDGET, WEEKLY_BUDGET,
                                f);


    fclose(l)
    return 0;
}