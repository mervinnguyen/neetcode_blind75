

/* Approach:
*
*   - The problem currently faced is to count the min adjacent swaps needed to group all 0s and all 1s together in a binary array. The input contains
*     the array, and the output will be the minimum # of swaps required to separate the 0s and 1s.
*   - One optimal approach would be to count how many swaps are needed to move all 0s to the left.
*   - For each 0, we will count how many 1s are before it (or for each 1, we will count how many 0s are before it)
*   - The sum of these counts will give us the minimum # of swaps that we will return.
*   
*   - Time: O(n)
*   - Space: O(1)
*/

int minMoves(int arr_count, int *arr){
    int ones_so_far = 0;
    int zeros_so_far = 0;
    int swaps_zeros_left = 0;
    int swaps_ones_left = 0;

    for(int i = 0; i < arr_count; i++){
        if (arr[i] == 1){
            ones_so_far++;
            swaps_ones_left += zeros_so_far;
        } else {
            zeros_so_far++;
            swaps_zeros_left += ones_so_far;
        }
    }
    return swaps_zeros_left < swaps_ones_left ? swaps_zeros_left : swaps_ones_left;
}