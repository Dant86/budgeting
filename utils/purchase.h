#include "timestamp.h"

#ifndef _PURCHASE_H_
#define _PURCHASE_H_

typedef struct purchase_ {
	float amt;
	char *desc;
	timestamp *ts;
} purchase;

purchase *empty_purchase();

purchase *new_purchase(float amount, char *description, char *date);

#endif