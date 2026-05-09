/**
 * @file ReorderList.cpp
 * @brief Given a singly linked list L0 -> L1 -> ... -> Ln, reorder it to L0 -> Ln -> L1 -> Ln-1 -> ... in-place.
 * @author Mervin Nguyen
 * @date 2026-05-09
 * @version 1.0.0
 */

 #include <iostream>

 using namespace std;
 
typedef struct Node {
    int data;
    struct Node *next;
} ListNode;

/**
 * @brief Reorder a singly linked list in-place.
 *
 * Reorders the list from L0 -> L1 -> ... -> Ln into
 * L0 -> Ln -> L1 -> Ln-1 -> ... by using the rabbit-and-hare method to
 * find the middle, reversing the second half, and merging the two lists
 * alternately.
 *
 * @param head Pointer to the head of the linked list.
 * @note The list is modified in-place.
 */
 void reorder_list(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev_slow = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev_slow != nullptr) {
        prev_slow->next = nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr != nullptr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *first = head;
    ListNode *second = prev;
    while (first != nullptr && second != nullptr) {
        ListNode *first_next = first->next;
        ListNode *second_next = second->next;

        first->next = second;
        if (first_next == nullptr) {
            break;
        }
        second->next = first_next;

        first = first_next;
        second = second_next;
    }
 }

void print_list(ListNode *head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
        if (head != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

 int main(void) {
    ListNode node5{5, nullptr};
    ListNode node4{4, &node5};
    ListNode node3{3, &node4};
    ListNode node2{2, &node3};
    ListNode node1{1, &node2};

    reorder_list(&node1);
    print_list(&node1);

    ListNode nodeB3{3, nullptr};
    ListNode nodeB2{2, &nodeB3};
    ListNode nodeB1{1, &nodeB2};

    reorder_list(&nodeB1);
    print_list(&nodeB1);

    return 0;
 }