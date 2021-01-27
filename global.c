#include "global.h"

const uint32_t ID_SIZE = SIZE_OF_ATTR(Row, id);
const uint32_t USERNAME_SIZE = SIZE_OF_ATTR(Row, username);
const uint32_t EMAIL_SIZE  = SIZE_OF_ATTR(Row, email);
const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

const uint32_t ID_OFFSET = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
