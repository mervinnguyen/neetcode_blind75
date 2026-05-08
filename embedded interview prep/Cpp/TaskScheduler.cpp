/**
 * @file TaskScheduler.cpp
 * @brief Given tasks and a cooldown interval n between same tasks, return the minimum intervals the CPU needs to finish all tasks.
 * @author Mervin Nguyen
 * @date 2026-05-08
 * @version 1.0.0
 */
 
 #include <iostream>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>

 using namespace std;

/**
 * @brief Calculate the minimum CPU intervals needed to complete all tasks with cooldown.
 *
 * Uses a greedy approach based on task frequency. The CPU must wait n intervals
 * between executing the same task. The minimum time is determined by either the
 * total number of tasks or the structure formed by the most frequent task(s).
 *
 * @param tasks A vector of task characters to be executed.
 * @param n The cooldown interval (minimum intervals between same tasks).
 * @return The minimum number of CPU intervals needed to complete all tasks.
 *
 * @note Time complexity: O(m log m) where m is the number of unique tasks.
 *       Space complexity: O(m) for the hash map and counts vector.
 *
 * @example
 * least_interval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) returns 8
 * least_interval({'A', 'A', 'A', 'B', 'B', 'B'}, 0) returns 6
 */
 int least_interval(vector<char> &tasks, int n) {
    unordered_map<char, int> task_counts;
    for (char task : tasks) {
        task_counts[task]++;
    }
    vector<int> counts;
    for (auto &entry : task_counts) {
        counts.push_back(entry.second);
    }
    sort(counts.begin(), counts.end(), greater<int>());
    int max_count = counts[0];
    int max_count_tasks = 1;
    for (int i = 1; i < counts.size(); i++) {
        if (counts[i] == max_count) {
            max_count_tasks++;
        } else {
            break;
        }
    }
    int part_count = max_count - 1;
    int part_length = n - (max_count_tasks - 1);
    int empty_slots = part_count * part_length;
    int available_tasks = tasks.size() - max_count * max_count_tasks;
    int idles = max(0, empty_slots - available_tasks);
    return tasks.size() + idles;
 }

 int main(void) {
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};

    int n1 = 2;
    int n2 = 0;
    int result_1 = least_interval(tasks1, n1);
    int result_2 = least_interval(tasks2, n2);

    cout << "The least interval for tasks1 is: " << result_1 << endl;
    cout << "The least interval for tasks2 is: " << result_2 << endl;

    return 0;
 }

