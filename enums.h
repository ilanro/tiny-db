//
//  enums.h
//

#ifndef enums_h
#define enums_h

typedef enum{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED,
} MetaCommandResult;

typedef enum{
    STATEMENT_CREATE_SUCCESS,
    STATEMENT_SYNTAX_ERR,
    STATEMENT_CREATE_FAIL,
} StatementPrepareResult;

typedef enum{
    STATEMENT_EXEC_SUCCESS,
    STATEMENT_EXEC_FAIL,
    
} StatementExecResult;

typedef enum{
    STATEMENT_SELECT,
    STATEMENT_INSERT,
} StatementType;

#endif /* enums_h */
