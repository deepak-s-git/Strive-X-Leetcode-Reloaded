/*
Problem: Remove Duplicates from Sorted List (LeetCode #83)
----------------------------------------------------------
Given the head of a **sorted** linked list, delete all duplicates such that 
each element appears only once. Return the linked list **sorted as well**.

Examples:
---------
Input: head = [1,1,2]  
Output: [1,2]

Input: head = [1,1,2,3,3]  
Output: [1,2,3]

Constraints:
------------
- The number of nodes in the list is in the range [0, 300].
- -100 <= Node.val <= 100
- The list is guaranteed to be sorted in non-decreasing order.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Single Pass (Iterative)
// -----------------------------------------------------------------------------
// Idea:
// - Since the list is already sorted, all duplicates appear consecutively.
// - Traverse the list and compare each node with its next.
// - If two adjacent nodes have the same value, skip the next node.
// - Otherwise, move forward normally.
//
// Why this works:
// - Sorted property ensures duplicates are next to each other.
// - One traversal is enough to remove all duplicates.
//
// Time Complexity: O(n)   → We visit each node once.
// Space Complexity: O(1)  → In-place modification, no extra memory used.
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;  // store original head to return later

        // Traverse the list while there are at least two nodes ahead
        while (head != NULL && head->next != NULL) {
            if (head->val == head->next->val) {
                // Duplicate found → skip the next node
                head->next = head->next->next;
            } else {
                // Move forward if values are different
                head = head->next;
            }
        }

        return res;  // return the modified list
    }
};
