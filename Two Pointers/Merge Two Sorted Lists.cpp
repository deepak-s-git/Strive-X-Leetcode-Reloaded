/*
Problem: Merge Two Sorted Lists (LeetCode #21)
-----------------------------------------------
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing 
together the nodes of the first two lists.

Return the head of the merged linked list.

Examples:
----------
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
-------------
- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both list1 and list2 are sorted in non-decreasing order.
*/

// -----------------------------------------------------------------------------
// Approach 1: Iterative Merge
// -----------------------------------------------------------------------------
/*
Idea:
- Initialize a pointer to the smaller head node.
- Use a "curr" pointer to build the merged list step by step.
- At each step, pick the smaller value node and attach it.
- Append the remainder of the other list once one becomes null.

Time Complexity: O(m+n)
Space Complexity: O(1) (in-place merge)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }

        ListNode* ptr = (list1->val <= list2->val) ? list1 : list2;
        if (list1->val <= list2->val) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }

        ListNode* curr = ptr;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = (list1 ? list1 : list2);
        return ptr;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Recursive Merge
// -----------------------------------------------------------------------------
/*
Idea:
- Base case: if one list is null, return the other.
- Compare heads of both lists:
  - The smaller one becomes the new head.
  - Recursively merge the remainder.

Time Complexity: O(m+n)
Space Complexity: O(m+n) due to recursion stack
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) {
            return head1 ? head1 : head2;
        }

        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};
