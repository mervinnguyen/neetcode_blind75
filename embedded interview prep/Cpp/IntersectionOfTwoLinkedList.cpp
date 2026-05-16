/**
 * @file IntersectionOfTwoLinkedList.cpp
 * @brief Given the heads of two singly linked list, return the node at whih they intersect, or null.
 * @date 2026-05-16
 * @version 1.0.0
 */
 #include <iostream>
 #include <unordered_set>

 using namespace std;

 typedef struct ListNode {
    int val;
    ListNode *next;
 } ListNode;

 /**
  * @brief Returns the node at which two singly linked lists intersect, or null if they don't.
  * @param headA Head of the first linked list.
  * @param headB Head of the second linked list.
  * @return Pointer to the intersecting node, or nullptr if no intersection exists.
  * @note Uses the two-pointer technique: each pointer redirects to the other list's head upon
  *       reaching null, equalizing total distance traveled to O(m+n). Time: O(m+n), Space: O(1).
  */
 ListNode *get_intersection_node(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    cout << "The intersection node is: " << (a ? a->val : -1) << endl;
    return a;
 }

 int main(void) {
    ListNode *headA = new ListNode{4, nullptr};
    headA->next = new ListNode{1, nullptr};
    headA->next->next = new ListNode{8, nullptr};
    headA->next->next->next = new ListNode{4, nullptr};
    headA->next->next->next->next = new ListNode{5, nullptr};

    ListNode *headB = new ListNode{5, nullptr};
    headB->next = new ListNode{6, nullptr};
    headB->next->next = new ListNode{1, nullptr};
    headB->next->next->next = headA->next->next; // Intersection at node with value 8

    get_intersection_node(headA, headB);

    return 0;
 }