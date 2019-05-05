#include <stdlib.h>
#include <string.h>
#include "timestamp.h"
#include "purchase.h"

purchase *empty_purchase() {
	purchase *p = malloc(sizeof(purchase));
	return p;
}

purchase *new_purchase(float amount, char *description, char *date) {
	if (description == NULL || date == NULL || amount <= 0)
		return NULL;
	timestamp *stamp = ts_from_str(date);
	if (stamp == NULL)
		return NULL;
	purchase *p = empty_purchase();
	if (p == NULL)
		return NULL;
	p -> amt = amount;
	p -> desc = strdup(description);
	p -> ts = stamp;
	return p;
}