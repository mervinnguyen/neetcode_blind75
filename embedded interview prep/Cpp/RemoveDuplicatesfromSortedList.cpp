/**
 * @file RemoveDuplicatesfromSortedList.cpp
 * @brief Given the head of a sorted linked list, delete all duplicates such that each element only appears only once.
 * @author Mervin Nguyen
 * @date 2026-04-17
 * @version 1.0.0
 */

#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} ListNode;

/*
 * Approach:
 * - Use a traversal pointer over the sorted list.
 * - If two adjacent nodes have the same value, unlink and free the duplicate.
 * - Otherwise, move forward.
*/
ListNode *delete_duplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            ListNode *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}

void print_list(const ListNode *head) {
    const ListNode *curr = head;
    while (curr != nullptr) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void free_list(ListNode *head) {
    while (head != nullptr) {
        ListNode *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    // Create linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 1;

    head->next = (ListNode *)malloc(sizeof(ListNode));
    head->next->data = 1;

    head->next->next = (ListNode *)malloc(sizeof(ListNode));
    head->next->next->data = 2;

    head->next->next->next = (ListNode *)malloc(sizeof(ListNode));
    head->next->next->next->data = 3;

    head->next->next->next->next = (ListNode *)malloc(sizeof(ListNode));
    head->next->next->next->next->data = 3;
    head->next->next->next->next->next = nullptr;

    auto result = delete_duplicates(head);

    print_list(result);
    free_list(result);

    return 0;
}