/**
 * @file MaximumProductSubarray.cpp
 * @brief Given an integer array, find the contiguous subarray that has the largest product.
 * @date 2026-05-11
 * @version 1.0.0
 */

 /*
    Example 1)
    Input: nums = [2,3,-2,4]
    Output: 6
    Explanation: The subarray [2,3] has the largest product 6.
 */

 /*
    Example 2)
    Input: nums = [-2,0,-1]
    Output: 0
    Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */
 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

 int max_product(vector<int> &nums) {
    if (nums.empty()) return 0;
    int max_prod = nums[0];
    int min_prod = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(max_prod, min_prod);
        }
        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);
        result = max(result, max_prod);
    }
    return result;
 }

 int main(void) {
    vector<int> nums1 = {2, 3, -2, 4};
    vector<int> nums2 = {-2, 0, -1};
    int result_1 = max_product(nums1);
    int result_2 = max_product(nums2);

    cout << "The maximum product of a subarray in nums1 is: " << result_1 << endl;
    cout << "The maximum product of a subarray in nums2 is: " << result_2 << endl;

    return 0;
 }
 