/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 void reorderList(ListNode* head) {
     if(head == nullptr) return;
     ListNode* middle = getMiddleNode(head);
     ListNode* secondList = middle -> next;
     middle -> next = nullptr;
     secondList = reverseLL(secondList);
     ListNode* first = head;
     ListNode* second = secondList;

     while (first != nullptr && second != nullptr) {
         ListNode* next = first -> next;
         ListNode* secondNext = second -> next;
         first -> next = second;
         second -> next = next;
         first = next;
         second = secondNext;
     }
 }

 ListNode* getMiddleNode(ListNode* head){
     ListNode* slow = head;
     ListNode* fast = head;

     while (fast -> next != nullptr && fast -> next -> next != nullptr) {
         slow = slow -> next;
         fast = fast -> next -> next;
     }

     return slow;
 }

 ListNode* reverseLL(ListNode* head){
     ListNode* current = head;
     ListNode *prev = nullptr, *next = nullptr;
     while (current != NULL) {
         next = current -> next;
         current -> next = prev;
         prev = current;
         current = next;
     }
     return prev;
 }
};
