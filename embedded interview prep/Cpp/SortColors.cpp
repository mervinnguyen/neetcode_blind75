/**
 * @file SortColors.cpp
 * @brief Given an array with objects colored red(0), white(1), or blue(2),
          sort them in-place.
 * @author Mervin Nguyen
 * @date 2026-05-09
 * @version 1.0.0
 */

 #include <iostream>
 #include <vector>

 using namespace std;

/**
 * @brief Sort array of 0s, 1s, and 2s in-place using the Dutch flag algorithm.
 *
 * Partitions the array into three regions: 0s on the left, 1s in the middle,
 * and 2s on the right. Uses three pointers (low, mid, high) to track boundaries.
 *
 * @param[in,out] nums Vector of integers containing only 0, 1, or 2.
 * @note Time complexity: O(n), Space complexity: O(1) (in-place sorting).
 */
 void sort_colors(vector<int> &nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
 }

 int main(void) {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sort_colors(nums);
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
 }
