/**
 * @file ContinuousSubarraySum.cpp
 * @brief Continuous Subarray Sum Solution
 * 
 * Given an integer array and an integer k, determine if the array has a
 * continuous subarray of size at least two whose elements sum up to a multiple of k.
 * 
 * @author Mervin Nguyen
 * @date 2026-05-02
 * @version 1.0.1
 * 
 * @example
 * - Input: nums = [23, 2, 4, 6, 7], k = 6 => Output: true (subarray [2, 4] sums to 6)
 * - Input: nums = [23, 2, 6, 4, 7], k = 13 => Output: false
 * - Input: nums = [1, 1, 1], k = 3 => Output: true (subarray [1, 1, 1] sums to 3)
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Checks if array contains a continuous subarray of size >= 2 summing to a multiple of k.
 * 
 * @param nums Reference to vector of integers to search
 * @param k The divisor to check for multiples
 * @return true if a valid subarray exists, false otherwise
 * 
 * @details Algorithm (Time: O(n), Space: O(min(n, k))):
 * - Track prefix sum remainders using a hash map
 * - If same remainder seen at indices i and j (j > i), then sum of elements between
 *   them is divisible by k
 * - Maintains constraint that subarray length >= 2 by storing first occurrence indices
 * - Special case: k == 0 requires finding consecutive zero-sum subarray
 */
bool checkSubarraySum(vector<int> &nums, int k) {
    // Need at least 2 elements for a valid subarray
    if (nums.size() < 2) {
        return false;
    }

    unordered_map<int, int> seen;  // Maps remainder to first occurrence index
    seen[0] = -1;                  // Initialize: remainder 0 at index -1

    long long prefixSum = 0;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        prefixSum += nums[i];

        // Calculate remainder key
        int key;
        if (k == 0) {
            key = static_cast<int>(prefixSum);
        } else {
            key = static_cast<int>(prefixSum % k);
            // Handle negative remainders
            if (key < 0) {
                key += (k > 0 ? k : -k);
            }
        }

        // Check if we've seen this remainder before
        if (seen.find(key) != seen.end()) {
            // Subarray from seen[key]+1 to i has sum divisible by k
            if (i - seen[key] >= 2) {
                return true;
            }
        } else {
            // Record first occurrence of this remainder
            seen[key] = i;
        }
    }

    return false;
}

/**
 * @brief Test the checkSubarraySum function with multiple test cases.
 */
int main(void) {
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    cout << "Test 1: [23,2,4,6,7], k=6 -> " << (checkSubarraySum(nums1, k1) ? "True" : "False") << endl;
    return 0;
}