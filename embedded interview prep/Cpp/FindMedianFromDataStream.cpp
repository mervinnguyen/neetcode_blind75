/**
 * @file FindMedianFromDataStream.cpp
 * @brief Design a data structure that supports adding integers from a stream and finding the median of all elements.
 * @author Mervin Nguyen
 * @date 2026-05-09
 * @version 1.0.0
 */
 #include <iostream>
 #include <queue>
 #include <vector>
 #include <functional>
 #include <iomanip>

/**
 * @class MedianFinder
 * @brief Maintains a stream of integers and efficiently returns the median.
 *
 * Uses the two-heap approach for optimal performance:
 * - A max-heap (priority_queue) for the lower half of numbers
 * - A min-heap (priority_queue with greater comparator) for the upper half
 *
 * Invariant: The sizes of the two heaps differ by at most 1, and all elements
 * in the lower heap are less than or equal to all elements in the upper heap.
 *
 * @note Time Complexity: addNum() - O(log n), findMedian() - O(1)
 * @note Space Complexity: O(n) for storing all numbers
 *
 * @author Mervin Nguyen
 */
class MedianFinder {
private:
    std::priority_queue<int> lo; // max-heap for lower half 
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi; // min-heap for upper half
public:
    /**
     * @brief Adds a number to the data stream.
     *
     * Maintains the two-heap invariant by inserting into the appropriate heap
     * and rebalancing if necessary. Time complexity: O(log n).
     *
     * @param num The integer to add to the stream.
     */
       void addNum(int num) {
            lo.push(num);
            hi.push(lo.top());
            lo.pop();

            if(lo.size() < hi.size()) {
                lo.push(hi.top());
                hi.pop();
            }
       }

    /**
     * @brief Returns the median of all numbers added so far.
     *
     * If the total count is odd, returns the middle element from the larger heap.
     * If even, returns the average of the two middle elements. Time complexity: O(1).
     *
     * @return The median as a double-precision floating-point number.
     */
       double findMedian() const {
            return lo.size() > hi.size() ? lo.top() : ((double)lo.top() + hi.top()) * 0.5;
    }
};

int main(void) {
       MedianFinder mf;
       mf.addNum(1);
       mf.addNum(2);
       std::cout << std::fixed << std::setprecision(1);
       std::cout << "Median after [1,2]: " << mf.findMedian() << "\n"; // 1.5
       mf.addNum(3);
       std::cout << "Median after [1,2,3]: " << mf.findMedian() << "\n"; // 2.0
       return 0;
}