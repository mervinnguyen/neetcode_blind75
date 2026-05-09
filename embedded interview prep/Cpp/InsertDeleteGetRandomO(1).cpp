/**
 * @file InsertDeleteGetRandomO(1).cpp
 * @brief Design a data structure that supports insert, delete, and getRandom operations in average O(1) time.
 * @date 2026-05-09
 * @version 1.0.0
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

/**
 * @brief RandomizedSet supports insert, remove, and getRandom in average O(1) time.
 *
 * The implementation stores values in a vector for O(1) random access and keeps
 * each value's index in an unordered_map so removals can swap the target with the
 * last element and pop in O(1).
 */
class RandomizedSet {
public:
        RandomizedSet() : rng(random_device{}()) {}

        /**
         * @brief Inserts a value if it does not already exist.
         * @param val Value to insert.
         * @return true if the value was inserted, false if it already existed.
         */
        bool insert(int val) {
                if (index_map.count(val) != 0) {
                        return false;
                }
                index_map[val] = values.size();
                values.push_back(val);
                return true;
        }

        /**
         * @brief Removes a value if it exists.
         * @param val Value to remove.
         * @return true if the value was removed, false otherwise.
         */
        bool remove(int val) {
                auto found = index_map.find(val);
                if (found == index_map.end()) {
                        return false;
                }

                size_t remove_index = found->second;
                int last_value = values.back();

                values[remove_index] = last_value;
                index_map[last_value] = remove_index;

                values.pop_back();
                index_map.erase(found);
                return true;
        }

        /**
         * @brief Returns a random element from the set.
         * @return A random value currently stored in the set.
         * @note The set must not be empty when this is called.
         */
        int getRandom() {
                if (values.empty()) {
                        return -1;
                }
                uniform_int_distribution<size_t> dist(0, values.size() - 1);
                return values[dist(rng)];
        }

private:
        vector<int> values;
        unordered_map<int, size_t> index_map;
        mt19937 rng;
};

int main(void) {
        RandomizedSet randomized_set;

        cout << boolalpha;
        cout << "insert(1): " << randomized_set.insert(1) << endl;
        cout << "remove(2): " << randomized_set.remove(2) << endl;
        cout << "insert(2): " << randomized_set.insert(2) << endl;
        cout << "getRandom(): " << randomized_set.getRandom() << endl;
        cout << "remove(1): " << randomized_set.remove(1) << endl;
        cout << "insert(2): " << randomized_set.insert(2) << endl;
        cout << "getRandom(): " << randomized_set.getRandom() << endl;

        return 0;
}