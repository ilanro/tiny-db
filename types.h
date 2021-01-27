//
//  types.h
//

#ifndef types_h
#define types_h

#include "enums.h"
#include "macros.h"

typedef struct{
    char *buffer;
    size_t buffer_size;
    ssize_t input_length;
} InputBuffer;

typedef struct{
    uint32_t id;
    char username[COLUMN_USERNAME_LEN];
    char email[COLUMN_EMAIL_LEN];
} Row;

typedef struct{
    StatementType type;
    Row row_to_insert;
} Statement;

#endif /* types_h */
