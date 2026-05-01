/**
 * @file addbinary.cpp
 * @brief Given two binary strings "a" and "b", return their sum as a binary string.
 *       Constraints: 1 <= a.length, b.length <= 10^4. a and b consist only of '0' or '1' characters. Each stirng d
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */
 #include <iostream>
 #include <stdio.h>
 #include <string>
 #include <algorithm>

 using namespace std;

 /**
 * @brief Adds two binary strings and returns their sum as a binary string.
 *
 * Approach: Single-pass ripple-carry from LSB to MSB using two index pointers.
 * Avoids integer conversion (overflows for strings up to 10^4 bits) and
 * minimizes allocations by building the result in reverse, then flipping once.
 *
 * Time:  O(max(n, m))
 * Space: O(max(n, m))  — result string only, no intermediate buffers
 *
 * @param a First binary string
 * @param b Second binary string
 * @return  Binary string representing a + b
 */
 string add_binary(string a, string b){
    string result;
    result.reserve(max(a.size(), b.size()) + 1);

    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if (i >= 0)
            sum += (a[i--] - '0');
        if (j >= 0)
            sum += (b[j--] - '0');
        result += static_cast<char>('0' + (sum & 1));
        carry = sum >> 1;
    }
    reverse(result.begin(), result.end());
    cout << "The sum of " << a << " and " << b << " is: " << result << endl;
    return result;
 }

 int main(void){
    string a = "11", b = "1";
    add_binary(a, b);
    return 0;
 }