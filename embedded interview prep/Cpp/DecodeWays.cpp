/**
 * @file DecodeWays.cpp
 * @brief Given a string containing only digits, return the number of ways to decode it where A=1, B=2, ..., Z=26.
 * @author Mervin Nguyen
 * @date 2026-05-04
 * @version 1.0.0
 */

/**
 * @example
 * Input: "12"
 * Output: 2
 * Explanation: "12" can be decoded as "AB" (1 2) or "L" (12).
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Count the number of valid decodings for a digit string.
 *
 * Uses dynamic programming with two rolling variables:
 * - `prev_two` stores the number of ways to decode up to index `i - 2`
 * - `prev_one` stores the number of ways to decode up to index `i - 1`
 *
 * For each position, the current number of ways is based on:
 * - The single-digit character at `s[i]`, if it is not '0'
 * - The two-digit substring `s[i - 1..i]`, if it forms a value from 10 to 26
 *
 * @param s The digit string to decode.
 * @return The total number of possible decodings.
 */
int num_decodings(string s) {
    if (s.empty() || s[0] == '0') {
        return 0;
    }
    int prev_two = 1;
    int prev_one = 1;
    for (size_t i = 1; i < s.size(); ++i) {
        int current = 0;
        if (s[i] != '0') {
            current += prev_one;
        }
        int two_digit = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (two_digit >= 10 && two_digit <= 26) {
            current += prev_two;
        }
        if (current == 0) {
            return 0;
        }
        prev_two = prev_one;
        prev_one = current;
    }
    return prev_one;
}

int main(void) {
    cout << num_decodings("12") << endl;
    cout << num_decodings("226") << endl;
    cout << num_decodings("06") << endl;

    return 0;
}