/**
 * @file MeetingRooms2.cpp
 * @brief Given an array of meeting time intervals, find the maximum number of conference rooms required.
 * @author Mervin Nguyen
 * @date 2026-05-16
 * @version 1.0.0
 */ 

 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

 /**
 * @details Separates interval start and end times into two sorted arrays,
 *          then applies a two-pointer sweep to track peak room usage.
 *          At each meeting start, if no room has freed up (start < earliest end),
 *          a new room is allocated. Otherwise, a room is reused and the end
 *          pointer advances. The running maximum captures the peak overlap.
 *
 *          Time complexity:  O(n log n) — dominated by sorting.
 *          Space complexity: O(n)       — two auxiliary arrays of size n.
 *
 * @param intervals A reference to a 2D vector of meeting intervals where
 *                  intervals[i] = {start_i, end_i}, with start_i < end_i.
 *                  Intervals do not need to be sorted.
 *
 * @return The minimum number of conference rooms required to hold all meetings.
 *
 * @note Assumes all intervals are valid (start < end) and the input is non-empty.
 *
 * @example
 * @code
 *   vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 25}};
 *   int rooms = min_meeting_rooms(intervals); // returns 2
 * @endcode
 */
 int min_meeting_rooms(vector<vector<int>> &intervals) {
    vector<int> starts, ends;
    for (auto &interval : intervals) {
        starts.push_back(interval[0]);
        ends.push_back(interval[1]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int rooms = 0, max_rooms = 0, j = 0;

    for (int i = 0; i < (int)starts.size(); i++) {
        if (starts[i] < ends[j]) {
            rooms++;
        } else {
            j++;
            rooms--;
        }
        max_rooms = max(max_rooms, rooms);
    }
    return max_rooms;
}

 int main(void) {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 25}};
    auto result = min_meeting_rooms(intervals);
    cout << "Min rooms required: " << result << endl;
    return 0;
 }