/**
 * @file FindtheDuplicateNumber.cpp
 * @brief Return the single repeated value in an array of n+1 integers in [1, n], without modifying nums and using constant extra space.
 * @author Mervin Nguyen
 * @date 2026-04-13
 * @version 1.0.0
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Finds the duplicate number using binary search on the value range
 *
 * The search is performed on values [1, n], not indices. For each midpoint,
 * it counts how many numbers are <= mid and narrows the range using the
 * pigeonhole principle.
 *
 * @param[in] nums Reference to the input vector of integers
 * @return The duplicated integer value
 * @note Time complexity: O(n log n), Space complexity: O(1)
 */
int find_duplicate(vector<int>&nums){
    int left = 1, right = nums.size() - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        int count = 0; 
        for (int x : nums){
            if (x <= mid){
                count++;
            }
        }
        if (count > mid){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    return left;
 }

int main(){
    vector<int> nums = {3,1,3,4,2};
    int result = find_duplicate(nums);
    printf("The duplicate in the array is: %d \n", result);
    return 0;
 }