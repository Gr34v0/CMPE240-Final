#include <stdio.h>
#include <stdlib.h>

#include "errorhandle.h"

int debug = 1;

void error_handle(char* errorMessage)
{
    perror(errorMessage); 
    exit(0);
}

void debug_msg(char* debugMessage)
{
    printf("%s", debugMessage);
}
