// getting information from the command line, with error checking
// operand operator operand
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "src/operations.h"

int32_t main(int32_t argc, char *argv[])
{    
    Operate(argv[1], argv[3], argv[2], argcheck(argc, argv[1], argv[3]));
}
