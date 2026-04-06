/**
 * @file NumberOf1Bits.cpp
 * @brief Implementation of Hamming weight calculation for 32-bit unsigned integers
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 * 
 * Approach:
 * - Iterate through all 32 bits of the integer.
 * - For each bit, check if it is 1 using (n & 1).
 * - Increment count for each 1 bit found.
 * - Shift n right by 1 after each check.
 * 
 */

#include <iostream>
#include <cstdint>

using namespace std;

class Solution{
public:
    /**
     * @brief Calculates the Hamming weight (number of 1 bits) of a 32-bit unsigned integer
     * 
     * @param[in] n 32-bit unsigned integer to analyze
     * @return Number of 1 bits in the input integer
     * 
     * @note Uses bit manipulation with right shift to examine each bit position
     */
    int hammingWeight(uint32_t n){
        int count = 0;
        for (int i = 0; i < 32; i++){
            count += (n & 1);    
            n >>= 1;   
        }
        return count;
    }
};

/**
 * @brief Main function demonstrating the Hamming weight calculation
 * 
 * @return Exit status code
 */
int main(){
    Solution sol;      
    uint32_t n = 0b00000000000001000001000000100100;
    cout << "The number of 1's is: " << sol.hammingWeight(n) << endl;
    return 0;
}