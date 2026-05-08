/**
 * @file HouseRobber.cpp
 * @brief Given an array representing money in each house, return the maximum amount you can rob without robbing two adjacent houses.
 * @author Mervin Nguyen
 * @date 2026-05-08
 * @version 1.0.0
 */

 #include <iostream>
 #include <vector>
 #include <cstdio>
 #include <algorithm>

 using namespace std;

/**
 * @brief Compute the maximum amount that can be robbed without taking adjacent houses.
 *
 * Uses dynamic programming where each entry stores the best result up to that house.
 *
 * @param nums The amount of money in each house.
 * @return The maximum amount that can be robbed.
 */
 int rob(vector<int> &nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp.back();
 }

 int main(void) {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 7, 9, 3, 1};
    int result_1 = rob(nums1);
    int result_2 = rob(nums2);

    cout << "The maximum amount that can be robbed from nums1 is: " << result_1 << endl;
    cout << "The maximum amount that can be robbed from nums2 is: " << result_2 << endl;

    return 0;
 }

