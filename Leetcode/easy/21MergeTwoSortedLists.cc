#include <iostream>

/*
Merge two sorted linked lists and return it as a sorted list. The list should
be made by splicing together the nodes of the first two lists.

Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *current1 = l1;
      ListNode *current2 = l2;
      ListNode *final = new ListNode();
      ListNode *current3 = final;
      while (current1 != NULL && current2 != NULL) {
        if (current1 -> val <= current2 -> val) {
          current3 -> next = current1;
          current3 = current3 -> next;
          current1 = current1 -> next;
        }
        else {
          current3 -> next = current2;
          current3 = current3 -> next;
          current2 = current2 -> next;
        }
      }

      if (current1 != NULL) {
        current3 -> next = current1;
      }
      else if (current2 != NULL) {
        current3 -> next = current2;
      }
      return final -> next;
    }
};
