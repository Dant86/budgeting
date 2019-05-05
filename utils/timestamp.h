#ifndef _TIMESTAMP_H_
#define _TIMESTAMP_H_

typedef struct timestamp_ {
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int second;
} timestamp;

timestamp *empty_timestamp();

timestamp *ts_from_str(char *str);

char *ts_to_str(timestamp *ts);

#endif