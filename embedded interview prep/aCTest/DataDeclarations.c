/**
 * @file DataDeclarations.c
 * @brief Demonstrates various data type declarations and pointer usage patterns
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

/**
 * @brief Integer variable declaration.
 */
int a = 0;

/**
 * @brief Pointer to an integer.
 */
int *p;

/**
 * @brief Pointer to a pointer to an integer.
 */
int **pp;

/**
 * @brief Array of 10 integers.
 */
int arr[10];

/**
 * @brief Array of 10 pointers to integers.
 */
int *parr[10];

/**
 * @brief Pointer to an array of 10 integers.
 */
int (*pArr)[10];

/**
 * @brief Pointer to a function that takes an integer as an argument and returns an integer.
 */
int (*funcPtr)(int);

/**
 * @brief Array of 10 pointers to functions that take an integer argument and return an integer.
 */
int (*funcPtrArr[10])(int);