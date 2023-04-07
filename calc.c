// getting information from the command line, with error checking
// operand operator operand
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int argccheck(int argc);
int checkargv(char *op);
void signedops(int32_t op1, int32_t op2, char *stringop, uint32_t *ur, int32_t *r, int *uns);

int main(int argc, char *argv[])
{

    argccheck(argc);
    int32_t op1 = checkargv(argv[1]);
    int32_t op2 = checkargv(argv[3]);
    int32_t result; //signed integer return value
    uint32_t uresult; //unsigned integer return value
    int uns = 0; //works like a flag that determines which return value to use, 1 for unsigned, 0 for signed
    signedops(op1,op2, argv[2], &uresult, &result, &uns); 
    if( uns == 1)
    {
        printf("%u\n", uresult);
    }
    else
    {
         printf("%d\n", result);
    }
}

int argccheck(
    int argc) // checks to see if the amount of arguments provided is correct
{
    if (argc != 4)
    {
        printf("incorrect amount of arguments provided\n");
        exit(1); // ends the program if incorrect amount of arguments
    }
    else
    {
        return 0;
    }
}

int checkargv(char *op) //checks the two operands to see if they contain anything except numbers
{
    for (int i = 0; i < (int)strlen(op); i++) //iterates through all numbers in the operand
    {
        if (op[i] < '0' || op[i] > '9')
        {
            printf("Incorrect input, enter only decimal numbers 0-9\n");   
            exit(1);
        }
    }
    return atoi(op);
}

void signedops(int32_t op1, int32_t op2, char *stringop, uint32_t *ur, int32_t *r, int *uns)
{
    uint32_t uop1 = (uint32_t) op1;
    uint32_t uop2 = (uint32_t) op2;
    uint32_t uresult;
    int32_t result;
    char operator= stringop[0];
    //printf("%c" , operator);
    switch (operator)
    {
    case '+':
    result = op1 + op2;
    break;
    case '-':
        result = op1 - op2;
    break;
    case '/':
        if (op2 == 0)
        {
            printf("Divide by Zero Error\n");
            exit(1);
        }
        else
        {
            result = op1 / op2;
        }
    break;
    case '*':
        result = op1 * op2;
    break;
    case '%':
        if (op2 == 0)
        {
            printf("Divide by Zero Error\n");
            exit(1);
        }
        result = op1 % op2;
    break;
    case '&':
        uresult = uop1 & uop2;
        *uns = 1;
    break;
    case '|':
        uresult = uop1 | uop2;
        *uns = 1;
    break;
    case '^':
        uresult = uop1 ^ uop2;
        *uns = 1;
    break;
    default:
        *uns = 1;
        if (strcmp(stringop, ">>") == 0)
        {
            uresult = uop1 >> uop2;
        }
        else if (strcmp(stringop, "<<") == 0)
        {
            uresult = uop1 << uop2;
        }
        else if (strcmp(stringop, "<<<") == 0)
        {
            uresult = (uop1 << uop2) | (uop1 >> (32 - uop2));
        }
        else if (strcmp(stringop, ">>>") == 0)
        {
            uresult = (uop1 >> uop2) | (uop1 << (32 - uop2));
        }
    }
    *ur = uresult;
    *r = result;
}



