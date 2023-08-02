/** @file operations.c
 * @brief This Source file contains functions that validate, format, and conduct
 *        arithmetic operation on command line input
 *
 * @author Connor Sorensen
 */    


#include "operations.h"

int32_t addition(int32_t op1, int32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    if (((op2 > INT32_MAX - op1) && (op1 > 0)) || ((op1 < 0) && (op2 < INT32_MIN - op1)))
    {
        fprintf(stderr, "Integer overflow/underflow detected\n");
    }
    else if((INT32_MAX == op2) || (INT32_MAX == op1))
    {
        fprintf(stderr, "Integer overflow/underflow detected\n");
    }
    else
    {
        fprintf(stdout, "%" PRId32 "\n", op1 + op2);
        
        ret_value = SUCCESS_VALUE;
    }

    return ret_value;
}

int32_t subtraction(int32_t op1, int32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    if (((op2 > 0) && (op1 < INT32_MIN + op2)) ||
        ((op2 < 0) && (op1 > INT32_MAX + op2)))
    {
        fprintf(stderr, "Integer overflow detected\n");
    }
    else if(((op1 > 0) && (op2 < INT32_MIN + op1)) ||
            ((op1 < 0) && (op2 > INT32_MAX + op1)))
    {
        fprintf(stderr,"Integer overflow detected");
    }    
    else if((INT32_MAX == op2) || (INT32_MAX == op1) || (INT32_MIN == op1) || (INT32_MIN == op2))
    {
        fprintf(stderr, "Integer overflow/underflow detected\n");
    }
    else
    {
        fprintf(stdout, "%" PRId32 "\n", op1 - op2);
        ret_value = SUCCESS_VALUE;
    }
    return ret_value;
}

int32_t divide(int32_t op1, int32_t op2)
{
        int32_t ret_value = ERROR_VALUE;

    if (0 == op2)
    {
        fprintf(stderr, "Divide by zero error.\n");
    }
    else if (((INT32_MIN == op1) && (-1 == op2)))
    {
        fprintf(stderr, "Signed Overflow\n");
    }
    else
    {
        fprintf(stdout, "%" PRId32 "\n", op1 / op2);
        ret_value = SUCCESS_VALUE;
    }
    return ret_value;
}

int32_t multiply(int32_t op1, int32_t op2)
{
    int32_t ret_value = ERROR_VALUE;
    if (((op1 > 0) && (op2 > 0) && (op1 > INT32_MAX / op2)))
    {
        goto OVERFLOW;
    }
    else if (((op1 > 0) && (op2 < 0) && (op2 < INT32_MAX / op1)))
    {
        goto OVERFLOW;
    }
    else if (((op1 < 0) && (op2 > 0) && (op1 < INT32_MAX / op2)))
    {
        goto OVERFLOW;
    }
    else if (((op1 < 0) && (op2 < 0) && (op2 < INT32_MAX / op1)))
    {
        goto OVERFLOW;
    }
    else
    {
        fprintf(stdout, "%" PRId32 "\n", op1 * op2);
        
        ret_value = SUCCESS_VALUE;
        goto END;
    }
OVERFLOW:
        fprintf(stderr, "Integer overflow detected\n");
END:        
    return ret_value;
}

int32_t modulus(int32_t op1, int32_t op2)
{
    int32_t ret_value = ERROR_VALUE;
    if (0 == op2)
    {
        fprintf(stderr, "Divide by zero error.\n");
    }
    else if (((INT32_MIN == op1) && (-1 == op2)))
    {
        fprintf(stderr, "Signed Overflow\n");
    }
    else
    {
        fprintf(stdout, "%" PRId32 "\n", op1 % op2);
        
        ret_value = SUCCESS_VALUE;
    }
    return ret_value;

}

int32_t right_shift(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", op1 >> op2);
    
    ret_value = SUCCESS_VALUE;
    
    return ret_value;
}

int32_t left_shift(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", op1 << op2);
    
    ret_value = SUCCESS_VALUE;
    
    return ret_value;
}

int32_t anding(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", op1 & op2);
    
    ret_value = SUCCESS_VALUE;
    
    return ret_value;
}

int32_t orring(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", op1 | op2);
    
    ret_value = SUCCESS_VALUE;

    return ret_value;
}

int32_t xorring(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", op1 ^ op2);
    
    ret_value = SUCCESS_VALUE;
    
    return ret_value;
}

int32_t left_rot(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", ((op1 << op2) | (op1 >> (32 - op2))));
    
    ret_value = SUCCESS_VALUE;
    
    return ret_value;
}

int32_t right_rot(uint32_t op1, uint32_t op2)
{
    int32_t ret_value = ERROR_VALUE;

    fprintf(stdout, "%" PRIu32 "\n", ((op1 >> op2) | (op1 << (32 - op2))));
    
    ret_value = SUCCESS_VALUE;
    
    return ret_value;
}


operator_t checkoperator(char* given_operator)
{
    int32_t ret_value = ERROR_VALUE;

    mappedoperator_t possibleoperators[] = {
        {"+\0",ADD},{"-\0",SUB},{"*\0",MUL},{"/\0",DIV},{"%\0",MOD},{"^\0",XOR},{"&\0",AND},
        {"|\0",ORR},{"<<\0",LSH},{">>\0",RSH},{"<<<\0",LRO},{">>>\0",RRO}
    };

    int32_t operator_value = ERROR_VALUE;
    for(int32_t counter = 0; counter < NUMOFOP; counter++)
    {
        if(strcmp(possibleoperators[counter].operator, given_operator) == SUCCESS_VALUE)
        {
            ret_value = possibleoperators[counter].mappedvalue;
            goto END;  
        }
    }
END:    
    return ret_value;
}

int32_t checkoperand(char *operand) 
{
    int32_t ret_value = ERROR_VALUE;

    char *badchar = NULL;
    
    if (0 != strtol(operand, &badchar, BASE) && (0 == *badchar))
    {
        ret_value = SUCCESS_VALUE;
    }
    else if(0 == strcmp("0\0", operand))
    {
        ret_value = SUCCESS_VALUE;
    }
    else
    {
        fprintf(stderr, "Please enter only decimal Numbers\n");
    }

END:    
    return ret_value;
}

int32_t operate(char *op1, char *op2, char* operator)
{
    int32_t ret_value = ERROR_VALUE;
    int32_t fop1 = 0; 
    int32_t fop2 = 0;
    uint32_t ufop1 = 0; 
    uint32_t ufop2 = 0;
    sscanf(op1, "%" SCNd32, &fop1);
    sscanf(op2, "%" SCNd32, &fop2); 
    sscanf(op1, "%" SCNu32, &ufop1);
    sscanf(op2, "%" SCNu32, &ufop2);
    operator_t operator_value = checkoperator(operator);

    if (((op1[0] == '-') || (op2[0] == '-')) && (UNSINTCODE < operator_value))
    {
        fprintf(stderr, "Cannot use negative numbers with bitwise operations\n");
        goto END;
    }
    else if(((INT32_MAX < strtoll(op1, NULL, BASE)) || (INT32_MAX < strtoll(op2, NULL, BASE))) && (UNSINTCODE > operator_value))
    {
        fprintf(stderr,"Integer overflow\n");
        goto END;
    }

    switch (operator_value)
    {
    case ADD :
        ret_value = addition(fop1, fop2);

        break;
    case SUB :
        ret_value = subtraction(fop1, fop2);

        break;
    case MUL :
        ret_value = multiply(fop1, fop2);

        break;
    case DIV :
        ret_value = divide(fop1, fop2);

        break;
    case MOD :
        ret_value = modulus(fop1, fop2);

        break;
    case XOR :
        ret_value = xorring(ufop1, ufop2);

        break;
    case AND :
        ret_value = anding(ufop1, ufop2);

        break;
    case ORR :
        ret_value = orring(ufop1, ufop2);

        break;
    case LSH :
        ret_value = left_shift(ufop1, ufop2);

        break;
    case RSH :
        ret_value = right_shift(ufop1, ufop2);

        break;
    case LRO :
        ret_value = left_rot(ufop1, ufop2);

        break;
    case RRO :
        ret_value = right_rot(ufop1, ufop2);

        break;
    default:
        fprintf(stderr,"No operator found\n");
    }

END:
   return ret_value;

}