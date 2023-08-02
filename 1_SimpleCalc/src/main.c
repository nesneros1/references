/** @file main.c
 * @author Connor Sorensen
 * @brief main function
 * @param argc An integer argument count of command line arguments
 * @param argv an array containing values of command line arguments
 * @return Will return zero upon success
 */

#include "operations.h"

int32_t main(int32_t argc, char **argv)
{
    int32_t ret_value = ERROR_VALUE;

    if (ARGCOUNT != argc)
    {
        fprintf(stderr, "incorrect amount of arguments provided\n");
    }
    else if((ERROR_VALUE != checkoperand(argv[OP1])) && (ERROR_VALUE != checkoperand(argv[OP2])))
    {
        ret_value = operate(argv[OP1],argv[OP2],argv[OPERATOR]);
    }
    
    END:
    return ret_value;

}