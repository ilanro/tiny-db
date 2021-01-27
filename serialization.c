#include "serialization.h"


void print_msg()
{
    printf("HELLLLO\n");
}

void serialize_row(Row *source_row, void *destination)
{
    // copy the source row's content into a memory location
    
    memcpy(destination + ID_OFFSET, &(source_row->id), ID_SIZE);
    memcpy(destination + USERNAME_OFFSET, &(source_row->id), USERNAME_SIZE);
    memcpy(destination + EMAIL_OFFSET, &(source_row->id), EMAIL_SIZE);
}

void deserialize_row(void *source, Row *destination_row)
{
    memcpy(&(destination_row->id), source + ID_OFFSET, ID_SIZE);
    memcpy(&(destination_row->id), source + USERNAME_OFFSET, USERNAME_SIZE);
    memcpy(&(destination_row->id), source + EMAIL_OFFSET, EMAIL_SIZE);
}

