/*
Problem: Remove Linked List Elements (LeetCode #203)
----------------------------------------------------
Given the head of a linked list and an integer `val`, remove all the nodes of 
the linked list that have `Node.val == val`, and return the new head.

Examples:
---------
Input: head = [1,2,6,3,4,5,6], val = 6  
Output: [1,2,3,4,5]

Input: head = [], val = 1  
Output: []

Input: head = [7,7,7,7], val = 7  
Output: []

Constraints:
------------
- The number of nodes in the list is in the range [0, 10^4].
- 1 <= Node.val <= 50
- 0 <= val <= 50
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Dummy Node + Iterative Traversal
// -----------------------------------------------------------------------------
// Idea:
// - Create a dummy node pointing to the head to simplify edge cases (e.g., when
//   the head itself needs to be removed).
// - Traverse the list and skip any node with the target value by adjusting
//   pointers.
// - Finally, return `dummy->next` as the new head.
//
// Why use a dummy node?
// - It prevents special handling for deleting the head node.
// - It simplifies pointer manipulation logic.
//
// Time Complexity: O(n)     → We traverse each node once.
// Space Complexity: O(1)    → No extra space used except dummy node.
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Step 1: Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Use a pointer to traverse the list
        ListNode* node = dummy;

        // Step 3: Skip nodes with the given value
        while (node->next != nullptr) {
            if (node->next->val == val) {
                node->next = node->next->next;  // remove node
            } else {
                node = node->next;  // move forward
            }
        }

        // Step 4: Return the new head
        return dummy->next;
    }
};
