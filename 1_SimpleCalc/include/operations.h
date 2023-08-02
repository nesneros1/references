/** @file operations.h
 * @brief This module contains functions that will both do input checking and
 * arithmetic operations.
 *  @author Connor Sorensen
 */

#ifndef _OPERATIONS_H
#define _OPERATIONS_H
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARGCOUNT 4
#define ERROR_VALUE -1
#define SUCCESS_VALUE 0
#define NUMOFOP 12
#define OP1 1
#define OP2 3
#define OPERATOR 2
#define BASE 10
#define UNSINTCODE 5

/**
 * @brief Enumerates the possible operations
*/
typedef enum {ADD,SUB,MUL,DIV,MOD,XOR,AND,ORR,LSH,RSH,LRO,RRO} operator_t;

/**
 * @brief Maps each string value of possible operators to an enumerated value 
 * which allows us to keep using the switch 
*/
typedef struct
{
    char* operator;
    operator_t mappedvalue;
} mappedoperator_t;

/** @brief Checks operator from CLI, gives it a value
 *  @param given_operator Assigns value to operator 
 *  @return -1 for failure 
*/
operator_t checkoperator(char* given_operator);

/** @brief This function performs mathematical operations on the input
 *  @param op1 A character array containing the first operand from CLI
 *  @param op2 A character array containing the second operand from CLI
 *  @param Operator A character array containing the operator from CLI
 *  @return 0 for success, 1 for failure and error message
 */
int32_t operate(char *op1, char *op2, char* operator);

/** @brief This function checks to see if the amount of provided arguments
 *         is correct
 *  @param argc The amount of command line arguments
 *  @return 0 for success or -1 for failure
 */
int32_t checkargc(int32_t argc);

/** @brief Checks the arguments for incorrect integer values, length, and
 * signage
 *  @param op The value of the input operator
 *  @return 0 for success and -1 for failure
 */
int32_t checkoperand(char *op);

/** @brief Adds(+) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t addition(int32_t op1, int32_t op2);

/** @brief subtracts(-) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t subtraction(int32_t op1, int32_t op2);

/** @brief divides (/) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t divide(int32_t op1, int32_t op2);

/** @brief multiplies(*) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t multiply(int32_t op1, int32_t op2);

/** @brief modulos(%) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t modulus(int32_t op1, int32_t op2);

/** @brief right shifts(>>) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t right_shift(uint32_t op1, uint32_t op2);

/** @brief left shifts(<<) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t left_shift(uint32_t op1, uint32_t op2);

/** @brief Anding(&) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t anding(uint32_t op1, uint32_t op2);

/** @brief Orring(|) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t orring(uint32_t op1, uint32_t op2);

/** @brief Xorring(^) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t xorring(uint32_t op1, uint32_t op2);

/** @brief left rotate(<<<) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t left_rot(uint32_t op1, uint32_t op2);

/** @brief right rotates(>>>) two numbers
 * @param op1 The first operand from command line
 * @param op2 The second operand from command line
 * @return  0 on success, -1 on failure
 */
int32_t right_rot(uint32_t op1, uint32_t op2);

#endif /*_OPERATIONS_H*/