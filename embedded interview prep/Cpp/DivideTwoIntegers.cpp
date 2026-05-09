/**
 * @file DivideTwoIntegers.cpp
 * @brief Given two integers, "dividend" and "divisor", divided two integers without using multiplcation, division, or mod operators.
          The integer division should truncate towards zero, which means losing its fractional part.

          Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [-2^31, 2^31 -1].
          If the quotient is strictly greater than 2^31 - 1, return 2^31 - 1, and if the quotient is strictly less than -2^31, return -2^31.

          Constraints: -2^31 <= dividend, divisor <= 2^31 - 1, divisor != 0.
 * @author Mervin Nguyen
 * @date 2026-05-09
 * @version 1.0.0
 */

 #include <iostream>
 #include <climits>
 
 using namespace std;

/**
 * @brief Divide two integers without using multiplication, division, or modulo.
 *
 * Uses bit shifting to repeatedly subtract the largest doubled divisor from
 * the dividend, which improves runtime over repeated single subtraction.
 *
 * @param dividend The numerator in the division operation.
 * @param divisor The denominator in the division operation (non-zero).
 * @return The quotient truncated toward zero, clamped to 32-bit signed range.
 * @note Time complexity is O(log(|dividend|)). Space complexity is O(1).
 */
 int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    long long ans = 0;
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        ans += multiple;
    }
    return sign * ans;
 }
 
 int main(void) {
    int dividend1 = 7;
    int divisor1 = -3;
    int result_1 = divide(dividend1, divisor1);

    cout << "The result of dividing " << dividend1 << " by " << divisor1 << " is: " << result_1 << endl;

    return 0;
 }