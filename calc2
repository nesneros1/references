// getting information from the command line, with error checking
// operand operator operand
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int argcheck(int argc, char *op1, char *op2);
int checkargv(char *op);
int Operate(int32_t op1, int32_t op2, char *Operator, int nFlag);

void Addition(int32_t op1, int32_t op2) 
{
    printf("%d\n", op1 + op2 );
}

void Subtraction(int32_t op1, int32_t op2)
{
    printf("%d\n", op1 - op2 );
}

void Divide(int32_t op1, int32_t op2)
{
    printf("%d\n", op1 / op2 );
}

void Multiply(int32_t op1, int32_t op2)
{
    printf("%d\n", op1 * op2 );
}

void Modulus(int32_t op1, int32_t op2)
{
    printf("%d\n", op1 % op2 );
}

void RightShift(uint32_t op1, uint32_t op2)
{
    printf("%u\n", op1 >> op2 );
}

void LeftShift(uint32_t op1, uint32_t op2)
{
    printf("%u\n", op1 << op2 );
}

void Anding(uint32_t op1, uint32_t op2)
{
    printf("%u\n", op1 & op2 );
}

void Orring(uint32_t op1, uint32_t op2)
{
    printf("%u\n", op1 | op2 );
}

void Xorring(uint32_t op1, uint32_t op2)
{
    printf("%u\n", op1 ^ op2 );
}

void LeftRot(uint32_t op1, uint32_t op2)
{
    printf("%u\n", (op1 << op2) | (op1 >> (32 - op2)) );
}

void RightRot(uint32_t op1, uint32_t op2)
{
    printf("%u\n", (op1 >> op2) | (op1 << (32 - op2)) );
}

int main(int argc, char *argv[])
{    
    Operate(atoi(argv[1]), atoi(argv[3]), argv[2], argcheck(argc, argv[1], argv[3]));
}

int argcheck(int argc, char *op1, char *op2) // checks to see if the amount of arguments provided is correct
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

int checkargv(char *op) //checks the two operands to see if they contain anything except numbers
{
    for (int i = 0; i < (int)strlen(op); i++) //iterates through all numbers in the operand
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

int Operate(int32_t op1, int32_t op2, char *Operator, int nFlag)
{
    uint32_t uop1 = (uint32_t) op1; //casts the variables as unsigned 
    uint32_t uop2 = (uint32_t) op2;
    switch (Operator[0])
    {
    case '+':
    Addition(op1, op2);
    break;
    case '-':
    Subtraction(op1, op2);
    break;
    case '/':
    Divide(op1, op2);
    break;
    case '*':
    Multiply(op1, op2);
    break;
    case '%':
    Modulus(op1, op2);
    break;
    default:
        if (nFlag == 1)
        {
            printf("Incorrect operator provided. Remember, cannot use a negative integer with bitwise operations\n");
        }
        else if (strcmp(Operator, ">>") == 0) //Grouped Bitwise operations in a seperate if else ladder due to switch only being able to compare single chars
        {
            RightShift(uop1, uop2);
        }
        else if (strcmp(Operator, "&") == 0)
        {
            Anding(uop1, uop2);
        }
        else if (strcmp(Operator, "|") == 0)
        {
            Orring(uop1, uop2);
        }
        else if (strcmp(Operator, "^") == 0)
        {
            Xorring(uop1, uop2);
        }
        else if (strcmp(Operator, "<<") == 0)
        {
            LeftShift(uop1, uop2);
        }
        else if (strcmp(Operator, "<<<") == 0)
        {
            LeftRot(uop1, uop2);
        }
        else if (strcmp(Operator, ">>>") == 0)
        {
            RightRot(uop1, uop2);
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
