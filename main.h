#ifndef main_h
#define main_h

#include "types.h"
#include "enums.h"
#include "macros.h"
#include "global.h"
#include "serialization.h"

InputBuffer* open_input_buffer(void);
void print_prompt(void);
void read_from_user(InputBuffer *);
void close_input_buffer(InputBuffer *);
void print_buffer_state(InputBuffer *);
MetaCommandResult exec_meta_command(InputBuffer *);
StatementPrepareResult prepare_statement(InputBuffer *,Statement *);
StatementExecResult execute_statement(Statement *);


#endif /* main_h */
