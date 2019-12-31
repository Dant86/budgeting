#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "ll.h"
#include "iohandler.h"

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
    int monthly = 500;
    int weekly = 100;
    FILE *ledger_f = NULL;
    int ix;
    if ((ix = find("-f", argv, argc)) > 0)
        ledger_f = fopen(argv[ix + 1], "r+");
    if ((ix = find("-w", argv, argc)) > 0) {
        weekly = atoi(argv[ix + 1]);
    }
    if ((ix = find("-m", argv, argc)) > 0) {
        monthly = atoi(argv[ix + 1]);
    }
    ledger *l = ledger_from_file(DEFAULT_TIME, monthly, weekly, ledger_f);

    char input[256];
    char c;
    while (1) {
        printf("input> ");
        scanf("%[^\t\n,]", input);
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
        parse_cmd(input, l);
    }


    free_ledger(l);
    if (ledger_f)
        fclose(ledger_f);
    return 0;
}