
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void Addition(int32_t op1, int32_t op2 ) 
{
    if((op2 > 0) && (op1 > 2^31 - op2) || op1 == 2^31 || op2 == 2^31)
    {
        fprintf(stdout, "Integer overflow detected\n");
    }
    else
    {
        fprintf(stdout,"%"PRId32"\n", op1 + op2 );
    }
    
}

void Subtraction(int32_t op1, int32_t op2)
{
    if((op1 > 2147483648 + op2) && (op2 < 0) || op1 == 2^31 || op2 == 2^31 )
    {
        fprintf(stdout, "Integer overflow detected\n");
    }
    else
    {
        fprintf(stdout,"%"PRId32"\n", op1 - op2 );
    }
}

void Divide(int32_t op1, int32_t op2)
{
    if (op2 == 0)
    {
        fprintf(stdout, "Divide by zero error.\n");
    }
    else
    {
        fprintf(stdout,"%"PRId32"\n", op1 / op2 );
    }
}

void Multiply(int32_t op1, int32_t op2)
{
    if ((op1 > INT32_MAX / op2) || op1 == 2^31 || op2 == 2^31)
    {
        fprintf(stdout, "Integer overflow detected\n");
    }
    else
    {
        fprintf(stdout,"%"PRId32"\n", op1 * op2 );
    }
    
}

void Modulus(int32_t op1, int32_t op2)
{
    if (op2 == 0)
    {
        fprintf(stdout, "Divide by zero error.\n");
    }
    else
    {
        fprintf(stdout,"%"PRId32"\n", op1 % op2 );
    }
}

void RightShift(uint32_t op1, uint32_t op2, int32_t flag)
{
    if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout, "%"PRIu32 "\n", op1 >> op2 );
    }
}

void LeftShift(uint32_t op1, uint32_t op2, int32_t flag)
{
    if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout, "%"PRIu32 "\n", op1 << op2 );
    }
}

void Anding(uint32_t op1, uint32_t op2, int32_t flag)
{
    if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout, "%"PRIu32 "\n", op1 & op2 );
    }
}

void Orring(uint32_t op1, uint32_t op2, int32_t flag)
{
    if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout, "%"PRIu32 "\n", op1 | op2 );
    }
}

void Xorring(uint32_t op1, uint32_t op2, int32_t flag)
{
    if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout, "%"PRIu32 "\n", op1 ^ op2 );
    }
}

void LeftRot(uint32_t op1, uint32_t op2, int32_t flag)
{
    if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout,"%"PRIu32"\n", (op1 << op2) | (op1 >> (32 - op2)));
    }
}

void RightRot(uint32_t op1, uint32_t op2, int32_t flag)
{
   if (flag != 0)
    {
        fprintf(stdout, "Cannot use signed integer with bitwise operations\n");
    }
    else
    {
        fprintf(stdout,"%"PRIu32"\n", (op1 >> op2) | (op1 << (32 - op2)));
    }
}

int32_t argcheck(int32_t argc, char *op1, char *op2) // checks to see if the amount of arguments provided is correct
{
    if (argc != 4)
    {
        printf("incorrect amount of arguments provided\n");
        exit(1); // ends the program if incorrect amount of arguments
    }
    if ((checkargv(op1) + checkargv(op2))  > 0) //if any operand is negative, return the signed flag
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int32_t checkargv(char *op) //checks the two operands to see if they contain anything except numbers
{
    for (int32_t i = 0; i < (int32_t)strlen(op); i++) //iterates through all numbers in the operand
    {
        if (((op[i] < '0' || op[i] > '9') && op[i] != '-')) 
        {
            printf("Incorrect input, enter only decimal numbers 0-9\n");   
            exit(1);
        }
    }
    if( op[0] == '-') //checks for the sign of the operand
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int32_t Operate(char* op1, char* op2, char *Operator, int32_t nflag)
{
    int32_t fop1,fop2;
    uint32_t ufop1,ufop2;
    sscanf(op1, "%" SCNd32, &fop1);
    sscanf(op2, "%" SCNd32, &fop2);   
    sscanf(op1, "%" SCNu32, &ufop1);
    sscanf(op2, "%" SCNu32, &ufop2);
    switch (Operator[0])
    {
    case '+':
    Addition(fop1, fop2);
    break;
    case '-':
    Subtraction(fop1, fop2);
    break;
    case '/':
    Divide(fop1, fop2);
    break;
    case '*':
    Multiply(fop1, fop2);
    break;
    case '%':
    Modulus(fop1, fop2);
    break;
    default:
        if (strcmp(Operator, ">>") == 0) //Grouped Bitwise operations in a seperate if else ladder due to switch only being able to compare single chars
        {
            RightShift(ufop1, ufop2, nflag);
        }
        else if (strcmp(Operator, "&") == 0)
        {
            Anding(ufop1, ufop2, nflag);
        }
        else if (strcmp(Operator, "|") == 0)
        {
            Orring(ufop1, ufop2, nflag);
        }
        else if (strcmp(Operator, "^") == 0)
        {
            Xorring(ufop1, ufop2, nflag);
        }
        else if (strcmp(Operator, "<<") == 0)
        {
            LeftShift(ufop1, ufop2, nflag);
        }
        else if (strcmp(Operator, "<<<") == 0)
        {
            LeftRot(ufop1, ufop2, nflag);
        }
        else if (strcmp(Operator, ">>>") == 0)
        {
            RightRot(ufop1, ufop2, nflag);
        }
        else
        {
            printf("Incorrect Operator provided\n");
            return 1;
        }
        return 0;
    }
    return 0;
}
