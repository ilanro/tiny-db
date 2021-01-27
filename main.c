//
//  main.c
//
//  Created by Ilan Rozen on 25/01/2021.
//

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"

int main(int argc, const char * argv[]) {
    
    InputBuffer *input_buffer = open_input_buffer();
    
    
    while(true)
    {
        print_prompt();
        read_from_user(input_buffer);
        
        if(!input_buffer->buffer[0])
            continue;
        
        // Test if the user entered a meta command to execute.
        if(input_buffer->buffer[0] == '.')
        {
            switch(exec_meta_command(input_buffer))
            {
                case META_COMMAND_UNRECOGNIZED:
                    printf("Coudln't recognize meta command: '%s'\n", input_buffer->buffer);
                    continue;
                case META_COMMAND_SUCCESS:
                    continue;
            }
        }
        
        Statement statememt;
        switch (prepare_statement(input_buffer, &statememt)) {
            case STATEMENT_CREATE_FAIL:
                printf("Couldn't recognize statement: '%s'\n", input_buffer->buffer);
                continue;
            default:
                break;
        }
        
        if(execute_statement(&statememt) == STATEMENT_CREATE_FAIL)
        {
            printf("Failed executing the statement\n");
        }
        
    }
    
}

InputBuffer* open_input_buffer()
{
    InputBuffer *res = (InputBuffer *)malloc(sizeof(InputBuffer));
    res->buffer = NULL;
    res->buffer = 0;
    res->input_length = 0;
    return res;
}

void close_input_buffer(InputBuffer *input_buffer)
{
    if(input_buffer)
    {
        if(input_buffer->buffer)
            free(input_buffer->buffer);
        free(input_buffer);
    }
}

void print_prompt()
{
    printf("db > ");
}

void read_from_user(InputBuffer* input_buffer)
{
    ssize_t res = getline(&input_buffer->buffer, &input_buffer->buffer_size, stdin);
    
    if(res<=0)
    {
        printf("Error reading line\n");
        close_input_buffer(input_buffer);
        exit(EXIT_FAILURE);
    }
    
    input_buffer->input_length = res - 1;
    input_buffer->buffer[res-1] = 0; //removing the newline char.
}

void print_buffer_state(InputBuffer* input_buffer)
{
    printf("Buffer content: %s\n", input_buffer->buffer);
    printf("Buffer content length: %zd\n", input_buffer->input_length);
    printf("Buffer size: %zu\n", input_buffer->buffer_size);
}


MetaCommandResult exec_meta_command(InputBuffer *input_buffer)
{
    if(strcmp(input_buffer->buffer, ".exit") == 0)
    {
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED;
    }
}

StatementPrepareResult prepare_statement(InputBuffer *input_buffer, Statement *target)
{
    if(strncmp(input_buffer->buffer, INSERT_COMMAND, 6) == 0)
    {
        int insert_id;
        char insert_name[20], insert_email[100];
        int argument_count = sscanf(input_buffer->buffer, "insert %d %s %s", &insert_id, insert_name, insert_email);
        if(argument_count < 3)
        {
            return STATEMENT_SYNTAX_ERR;
        }
        if(input_buffer->buffer[6]==' ' || strlen(input_buffer->buffer) == 6)
        {
            target->type = STATEMENT_INSERT;
            return STATEMENT_CREATE_SUCCESS;
        }
    }
    if(strcmp(input_buffer->buffer, SELECT_COMMAND) == 0)
    {
        target->type = STATEMENT_SELECT;
        return STATEMENT_CREATE_SUCCESS;
    }
    
    return STATEMENT_CREATE_FAIL;
}

StatementExecResult execute_statement(Statement *statement)
{
    switch(statement->type)
    {
        case STATEMENT_SELECT:
            printf("Performing select\n");
            return STATEMENT_EXEC_SUCCESS;
        case STATEMENT_INSERT:
            printf("Performing insert\n");
            return STATEMENT_EXEC_SUCCESS;
    }
    
    return STATEMENT_EXEC_FAIL;
}

