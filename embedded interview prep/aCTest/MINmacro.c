/**
 * @brief Standard MIN macro to return the smaller of two arguments.
 * 
 * Always parenthesize macro arguments and the entire expression to avoid precedence bugs.
 * 
 * @param A First value to compare
 * @param B Second value to compare
 * @return The smaller of the two input values
 * @note Arguments are evaluated twice - avoid using expressions with side effects
 * @warning This macro evaluates each argument twice, which can cause issues with
 *          function calls or increment/decrement operations
 */
#define MIN(A,B)    (((A) < (B)) ? (A) : (B))