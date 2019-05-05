#include <stdio.h>
#include <stdlib.h>
#include "utils/purchase.h"
#include "utils/timestamp.h"

#define MONTHLY_BUDGET 500;
#define WEEKLY_BUDGET 100;

char *read_line(int max_len) {
	char *str = malloc(max_len * sizeof(char));
	int ctr = 0;
	char c = getchar();
	while (c != '\n') {
		str[ctr] = c;
		ctr++;
		c = getchar();
	}
	str[ctr] = '\0';
	return str;
}

int main(int argc, char *argv[]) {
	return 0;
}