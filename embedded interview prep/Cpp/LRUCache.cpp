/**
 * @brief Problem:
 * Design a Least Recently Used (LRU) Cache supporting get and put operations in O(1) time.
 *
 * @par Example 1:
 * Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 *        [[2], [1,1], [2,2], [1], [3,3], [2], [4,4], [1], [3], [4]]
 * Output: [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * @par Explanation:
 * Cache capacity=2. When put(3,3) is called, key 2 is evicted (least recently used).
 * When put(4,4) is called, key 1 is evicted.
 */
#include <bits/stdc++.h>

using namespace std; 

/**
 * @brief Approach:
 * - Use a data structure that allows fast key lookup: a hashmap (unordered_map).
 * - Maintain the order of keys from most recently used to least recently used, so when the cache is full and a new item is inserted, the least recently used key can be evicted.
 *
 * @details
 * Solution:
 * - Implement a doubly linked list (head = least recently used, tail = most recently used).
 * - Map each key to its value and a pointer to its node in the doubly linked list.
 * - Function 1: get(key): Move the node to the front and return its value.
 * - Function 2: put(key, value): If the key exists, update the value and move its node to the front.
 *
 * @note
 * - Time Complexity: O(1)
 * - Space Complexity: O(1)
 */

class LRUCache {
private:
    int capacity;

    //doubly linked list that stores (key, value) pair
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    /* Move an existing key's node to the back (most recently used)*/
    void move_to_back(int key){
        auto it = mp[key];
        auto kv = *it;
        dll.erase(it);
        dll.push_back(kv);
        mp[key] = prev(dll.end());
    }

public: 
    LRUCache(int capacity) : capacity(capacity){}

    int get(int key){
        if(mp.find(key) == mp.end()){
            return -1;
        }

        move_to_back(key);

        return mp[key]->second;
    }

    void put(int key, int value){
        if (capacity == 0){
            return;
        }

        auto it = mp.find(key);
        
        if (it != mp.end()){
            /* key already exists: update value and mark as most recently used*/
            it->second->second = value;
            move_to_back(key);
        } else{
            if ((int)mp.size() == capacity){
                /* If the cache is full, evict the least recently used (front of the list)*/
                int lruKey = dll.front().first;
                dll.pop_front();
                mp.erase(lruKey);
            }
            dll.push_back({key, value});
            mp[key] = prev(dll.end());
        }
    }
};