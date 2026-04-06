/**
 * @file LinkedListCycle.cpp
 * @brief Detects if a singly linked list contains a cycle using Floyd's Tortoise and Hare algorithm
 * @author Mervin
 * @date 2026-03-28
 * @version 1.0.0
 */

class Solution {
public:
    typedef struct Node{
        int data;           
        struct Node *next; 
    } ListNode;
    
    /**
     * @brief Determines if a linked list has a cycle using Floyd's Tortoise and Hare algorithm
     * 
     * Uses two pointers moving at different speeds (slow moves 1 step, fast moves 2 steps).
     * If a cycle exists, the fast pointer will eventually meet the slow pointer.
     * 
     * @param[in] head Pointer to the head of the linked list
     * @return true if a cycle exists, false otherwise
     * @note Time complexity: O(n), Space complexity: O(1)
     */
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head; 
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};