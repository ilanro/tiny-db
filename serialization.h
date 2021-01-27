#ifndef serialization_h
#define serialization_h

#include <stdio.h>

#include <string.h>
#include "global.h"
#include "types.h"

void print_msg(void);

void serialize_row(Row *, void *);
void deserialize_row(void *, Row *);

#endif /* serialization_h */
