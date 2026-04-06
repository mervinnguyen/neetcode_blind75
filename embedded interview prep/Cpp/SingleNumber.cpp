/**
 * @file SingleNumber.cpp
 * @brief Implementation of single number finder using XOR operation
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    /**
     * @brief Finds the single number that appears once while all others appear twice
     * @param[in] nums Vector of integers where all numbers appear twice except one
     * @return The single number that appears only once
     * @note Uses XOR operation which cancels out duplicates due to A XOR A = 0 property
     */
    int singleNumber(vector<int> &nums){
        int result = 0;
        for (int num : nums){
            result ^= num;
        }
        return result;
    }
};

/**
 * @brief Main function demonstrating the single number algorithm
 * @return Exit status code
 */
int main(){
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 3};
    cout << "Single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}