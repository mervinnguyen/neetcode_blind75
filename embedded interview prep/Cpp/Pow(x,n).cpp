/**
 * @file Pow(x,n).cpp
 * @brief Implement pow(x, n), which calculates x raised to the power n.
 * @author Mervin Nguyen
 * @date 2026-05-09
 * @version 1.0.0
 */

 #include <iostream>
 #include <cmath>

 using namespace std;
 
/**
 * @brief Compute x raised to the power n using fast exponentiation.
 *
 * Handles negative exponents by inverting the base and using a 64-bit
 * exponent accumulator to avoid overflow when n == INT_MIN.
 *
 * @param x The base value.
 * @param n The exponent value.
 * @return x raised to the power n.
 * @note Time complexity is O(log |n|) and space complexity is O(1).
 */
double my_pow(double x, int n) {
    if (n == 0) return 1.0;
    long long exp = n;
    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }
    double result = 1.0;
    while (exp > 0) {
        if (exp & 1) result *= x;
        x *= x;
        exp >>= 1;
    }
    return result;
}

 int main(void) {
    double x1 = 2.0;
    int n1 = 10;
    double result_1 = my_pow(x1, n1);

    double x2 = 2.1;
    int n2 = 3;
    double result_2 = my_pow(x2, n2);

    cout << "The result of " << x1 << " raised to the power of " << n1 << " is: " << result_1 << endl;
    cout << "The result of " << x2 << " raised to the power of " << n2 << " is: " << result_2 << endl;

    return 0;
 }
