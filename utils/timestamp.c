#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timestamp.h"

timestamp *empty_timestamp() {
	timestamp *ts = malloc(sizeof(timestamp));
	return ts;
}

/*
	all timestamps are in the form:
	"MM/DD/YYYY hh:mm:ss"
*/
timestamp *ts_from_str(char *str) {
	if (str == NULL)
		return NULL;
	timestamp *ts = empty_timestamp();
	if (ts == NULL)
		return NULL;
	int res = sscanf(str, "%d/%d/%d %d:%d:%d", &ts -> month, &ts -> day, &ts -> year, &ts -> hour, &ts -> minute, &ts -> second);
	return res == 6 ? ts : NULL;
}

char *ts_to_str(timestamp *ts) {
	if (ts == NULL)
		return NULL;
	char *s = malloc((sizeof(char) * 18) + 1);
	sprintf(s, "%02d/%02d/%04d %02d:%02d:%02d", ts -> month, ts -> day, ts -> year, ts -> hour, ts -> minute, ts -> second);
}