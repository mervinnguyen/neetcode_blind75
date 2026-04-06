/**
 * @file reverselinkedlist.c
 * @brief Reverse a singly linked list implementation
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node *next;
};

struct Node *reverse_linked_list(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(void) {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 1;
    second->data = 1;
    third->data = 1;

    head = reverse_linked_list(head);
    printf("%d -> ", head->data);
    return 0;
}