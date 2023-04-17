#include <inttypes.h>

#ifndef operations_h
#define operations_h
int32_t argcheck(int32_t argc, char *op1, char *op2);

int32_t checkargv(char *op);

int32_t Operate(char* op1, char* op2, char *Operator, int32_t nflag);
    
void Addition(int32_t op1, int32_t op2 );

void Subtraction(int32_t op1, int32_t op2);

void Divide(int32_t op1, int32_t op2);

void Multiply(int32_t op1, int32_t op2);

void Modulus(int32_t op1, int32_t op2);

void RightShift(uint32_t op1, uint32_t op2, int32_t flag);

void LeftShift(uint32_t op1, uint32_t op2, int32_t flag);

void Anding(uint32_t op1, uint32_t op2, int32_t flag);

void Orring(uint32_t op1, uint32_t op2, int32_t flag);

void Xorring(uint32_t op1, uint32_t op2, int32_t flag);

void LeftRot(uint32_t op1, uint32_t op2, int32_t flag);

void RightRot(uint32_t op1, uint32_t op2, int32_t flag);

#endif