/**
 * @file DotProductTwoSparseVectors.cpp
 * @brief Computes the dot product of two sparse vectors.
 * @author Mervin Nguyen
 * @date 2026-04-13
 * @version 1.0.0
 */

 #include <iostream>
 #include <vector>

 using namespace std;

/**
 * @brief Returns the dot product of two integer vectors.
 *
 * Assumes both vectors have the same length and computes the sum of
 * pairwise products.
 *
 * @param[in] nums1 Reference to the first input vector
 * @param[in] nums2 Reference to the second input vector
 * @return The dot product of nums1 and nums2
 * @note Time complexity: O(n), Space complexity: O(1)
 */
 int dot_product(vector<int> &nums1, vector<int> &nums2){
    int result = 0;
    for (size_t i = 0; i < nums1.size(); i++){
        result += nums1[i] * nums2[i];
    }
    return result;
 }

 int main(){
    vector<int> nums1 = {1, 0, 0, 2, 3};
    vector<int> nums2 = {0, 3, 0, 4, 0};
    int result = dot_product(nums1, nums2);
    cout << "The dot product of nums1 and nums2 is : " << result << endl;
    return 0;
 }