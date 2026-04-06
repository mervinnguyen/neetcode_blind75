/**
 * @file ContainsDuplicate.cpp
 * @brief Implementation of duplicate detection in integer arrays
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 * 
 * Approach:
 * 1. Sort the array in order.
 * 2. Iterate through the array, comparing each element to the previous one.
 * 3. If any two consecutive elements are equal, return true (duplicate found).
 * 4. If no duplicates are found, return false.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    /**
     * @brief Checks if an array contains any duplicate values
     * @param[in,out] nums Vector of integers to check (modified by sorting)
     * @return true if duplicates exist, false otherwise
     * @note Time complexity: O(n log n) due to sorting, Space complexity: O(1)
     */
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 4, 3, 2};
    bool result = sol.hasDuplicate(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}