/**
 * @file MaximumSwap.cpp
 * @brief Given a non-negative integer, swap two digits at most once to get the maximum valued number.
 * @author Mervin Nguyen
 * @date 2026-05-08
 * @version 1.0.0
 */ 

 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <string>
 
 using namespace std;

/**
 * @brief Swap two digits at most once to get the maximum valued number.
 *
 * Uses a greedy approach: for each position from left to right, finds the largest
 * digit to its right and swaps if it is greater. At most one swap is performed.
 *
 * @param num A non-negative integer.
 * @return The maximum valued number after at most one swap.
 *
 * @example
 * maximum_swap(2736) returns 7326
 * maximum_swap(9973) returns 9973
 */
 int maximum_swap(int num) {
    string num_string = to_string(num);
    int last[10] = {0};
    for (int i = 0; i < num_string.size(); i++) {
        last[num_string[i] - '0'] = i;
    }
    for (int i = 0; i < num_string.size(); i++) {
        for (int d = 9; d > num_string[i] - '0'; d--) {
            if (last[d] > i) {
                swap(num_string[i], num_string[last[d]]);
                return stoi(num_string);
            }
        }
    }
    return num;
 }

 int main(void) {
    int num1 = 2736;
    int num2 = 9973;
    int result_1 = maximum_swap(num1);
    int result_2 = maximum_swap(num2);

    cout << "The maximum swap for num1 is: " << result_1 << endl;
    cout << "The maximum swap for num2 is: " << result_2 << endl;

    return 0;
 }