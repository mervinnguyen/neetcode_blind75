/**
 * @file DeleteNodeinLinkedList.cpp
 * @brief Delete Node in a Linked List - Solution to delete a node when only given access to that node
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>

using namespace std;

typedef struct Node {
    int data;          
    struct Node *next; 
} ListNode;

/**
 * @brief Delete a node in a singly linked list given only access to that node
 * 
 * This function implements the copy-and-skip technique:
 * 1) Copy the next node's value into the current node
 * 2) Store reference to the next node
 * 3) Skip the next node by updating the current node's next pointer
 * 4) Delete the stored next node
 * 
 * @param[in] node Pointer to the node to be deleted (must not be the tail node)
 * 
 * @note This approach only works if the node to delete is not the tail node
 * @warning Assumes node and node->next are not NULL
 */
void delete_node(ListNode *node){
    node -> data = node -> next -> data;    
    ListNode * temp = node -> next;         
    node -> next = node -> next -> next;    
    delete temp;                            
}

int main(void) {
    // Create linked list: 4 -> 5 -> 1 -> 9
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));

    n1->data = 4; 
    n1->next = n2;
    n2->data = 5; 
    n2->next = n3;
    n3->data = 1; 
    n3->next = n4;
    n4->data = 9; 
    n4->next = NULL;

    cout << "Original list: ";
    ListNode* curr = n1;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    delete_node(n2);

    cout << "After deleting node 5: ";
    curr = n1;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    free(n1);
    free(n2); 
    free(n3); 
    free(n4);

    return 0;
}