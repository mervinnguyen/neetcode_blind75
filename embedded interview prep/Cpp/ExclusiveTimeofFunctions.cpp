/**
 * @file ExclusiveTimeofFunctions.cpp
 * @brief Calculate exclusive time of functions on a single-threaded CPU from start/end logs.
 * @author Mervin Nguyen
 * @date 2026-05-04
 * @version 1.0.0
 * 
 * @details
 * Given n functions with start/end logs on a single-threaded CPU, calculate the exclusive
 * time each function runs (not counting time spent in nested function calls).
 * 
 * @example
 * Input: n = 2, logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]
 * Output: [3, 4]
 * Explanation: Function 0 runs 0-1 (2 units) and 6-6 (1 unit) = 3 total
 *              Function 1 runs 2-5 (4 units) = 4 total
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

/**
 * @struct Log
 * @brief Represents a parsed log entry
 */
struct Log {
    int id;          ///< Function ID
    string type;     ///< Event type: "start" or "end"
    int timestamp;   ///< Timestamp of the event
};

/**
 * @brief Parse a log string into its components.
 * 
 * Parses a log entry string in the format "id:start/end:timestamp" into
 * a Log struct with separate fields for each component.
 * 
 * @param s Log string in format "id:start/end:timestamp" (e.g., "0:start:0")
 * @return Log struct with parsed id, type, and timestamp
 */
 Log get_log(string &s) {
    int colon_one = s.find(':');
    int colon_two = s.find(':', colon_one + 1);

    int id = stoi(s.substr(0, colon_one));
    string type = s.substr(colon_one + 1, colon_two - colon_one - 1);
    int timestamp = stoi(s.substr(colon_two + 1));

    return {id, type, timestamp};
 }

/**
 * @brief Calculate exclusive execution time for each function.
 * 
 * Uses a stack-based approach to track nested function calls and calculate
 * the exclusive time each function runs on the CPU (excluding time spent
 * in child function calls).
 * 
 * @param n Number of functions
 * @param logs Vector of log strings in format "id:start/end:timestamp"
 * 
 * @return Vector where result[i] = exclusive execution time of function i
 * 
 * @note Algorithm:
 *   - Use a stack to track (function_id, start_time) pairs
 *   - For START events: add parent's accumulated time, then push new function
 *   - For END events: pop function, calculate exclusive time, update parent's resume point
 * 
 * @note Complexity:
 *   - Time: O(n) where n is number of logs
 *   - Space: O(d) where d is maximum nesting depth
 */
 vector<int> exclusive_time(int n, vector<string> &logs) {
    vector<int> result(n, 0);
    stack<pair<int, int>> st;

    for (string &log : logs) {
        Log entry = get_log(log);

        if (entry.type == "start") {
            // Add accumulated time for current function before pushing new one
            if (!st.empty()) {
                int parent_time = entry.timestamp - st.top().second;
                result[st.top().first] += parent_time;
            }
            st.push({entry.id, entry.timestamp});
        } 
        else { // end
            auto [func_id, start_time] = st.top();
            st.pop();

            int exclusive = entry.timestamp - start_time + 1;
            result[func_id] += exclusive;

            // Update parent's resume point
            if (!st.empty()) {
                st.top().second = entry.timestamp + 1;
            }
        }
    }
    return result;
 }

/**
 * @brief Main function - tests the exclusive_time implementation.
 * 
 * @return 0 on successful execution
 */
 int main(void) {
    // Test Case 1: Simple start and end
    int n1 = 2;
    vector<string> logs1 = {"0:start:0", "0:end:0"};
    vector<int> result1 = exclusive_time(n1, logs1);
    cout << "Test 1: ";
    for (int t : result1) cout << t << " ";
    cout << endl;

    // Test Case 2: Nested functions
    int n2 = 2;
    vector<string> logs2 = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
    vector<int> result2 = exclusive_time(n2, logs2);
    cout << "Test 2: ";
    for (int t : result2) cout << t << " ";
    cout << endl;

    // Test Case 3: Multiple nested levels
    int n3 = 3;
    vector<string> logs3 = {"0:start:0", "1:start:1", "2:start:2", "2:end:5", "1:end:6", "0:end:7"};
    vector<int> result3 = exclusive_time(n3, logs3);
    cout << "Test 3: ";
    for (int t : result3) cout << t << " ";
    cout << endl;

    return 0;
 }