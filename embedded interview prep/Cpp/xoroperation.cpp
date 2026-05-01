/**
 * @file xoroperation.cpp
 * @brief Given integers "n" and "start", compute the bitwise XOR of an array "nums" where "nums[i] = start + 2 * i".
 * @author Mervin Nguyen
 * @date 2026-04-30
 * @version 1.0.0
 * 
 * @details
 * Constraints: 1 <= n <= 1000, 0 <= start <= 1000
 * 
 * Example:
 * Input: n = 5, start = 0
 * Output: 8 (array: [0, 2, 4, 6, 8], 0 ^ 2 ^ 4 ^ 6 ^ 8 = 8)
 */

#include <iostream>
#include <cstdio>

/**
 * @brief Computes the bitwise XOR of all elements in the virtual array.
 * @param n The number of elements in the array
 * @param start The starting value for array generation
 * @return The XOR result of all elements
 */

int xor_operation(int n, int start){
    int result = 0;
    int nums[n];
    for (int i = 0; i < n; i++){
        nums[i] = start + 2 * i;
    }
    for (int i = 0; i < n; i++){
        result ^= nums[i];
    }
    printf("The bitwise XOR of all elements of 'nums' is: %d\n", result);
    return 0;
}

int main(){
    int n = 5, start = 0;
    xor_operation(n, start);
    return 0;
}