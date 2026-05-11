/**
 * @file ReverseIntegerWithoutUsingLongLong.cpp
 * @brief Given a signed 32-bit integer, return its digits reversed, returning 0 if the result overflows.
 * @author Mervin Nguyen
 * @date 2026-05-11
 * @version 1.0.0
 */
 
 #include <iostream>
 #include <climits>

 using namespace std;

/**
 * @brief Reverse digits of a 32-bit signed integer without using 64-bit types.
 *
 * Pops digits off the input integer and pushes them onto the reversed result
 * while checking for overflow before each multiply/add. Returns 0 when the
 * reversed value would overflow the 32-bit signed integer range.
 *
 * @param x The integer to reverse.
 * @return The reversed integer or 0 if it overflows 32-bit signed range.
 * @note Time complexity: O(d) where d is number of digits. Space: O(1).
 */
int reverse(int x) {
   int rev = 0;
   while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
      rev = rev * 10 + pop;
   }
   return rev;
}

 int main(void) {
    int x1 = 123;
    int x2 = -123;
    int x3 = 1534236469;

    int result_1 = reverse(x1);
    int result_2 = reverse(x2);
    int result_3 = reverse(x3);

    cout << "The reverse of " << x1 << " is: " << result_1 << endl;
    cout << "The reverse of " << x2 << " is: " << result_2 << endl;
    cout << "The reverse of " << x3 << " is: " << result_3 << endl;

    return 0;
 }