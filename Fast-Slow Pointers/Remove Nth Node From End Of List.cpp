/*
Problem: Remove Nth Node From End of List (LeetCode #19)
--------------------------------------------------------
Given the head of a linked list, remove the n-th node from the end of the list 
and return its head.

Examples:
---------
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]

Constraints:
------------
- The number of nodes in the list is sz.
- 1 <= sz <= 30
- 0 <= Node.val <= 100
- 1 <= n <= sz
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Two Pointers (Fast & Slow) + Dummy Node
// -----------------------------------------------------------------------------
// Idea:
// - Use a dummy node before head to simplify edge cases (like removing the first node).
// - Move `head` pointer `n` steps ahead.
// - Then, move both `head` and `dummy` until `head` reaches the end.
// - Now, `dummy` is just before the node we want to remove.
// - Update `dummy->next` to skip the nth node from the end.
//
// Why this works:
// - The distance between `head` and `dummy` ensures we land just before the target node.
// - Using a dummy node makes removing the head node easy without special cases.
//
// Time Complexity: O(L) — where L is the length of the list.
// Space Complexity: O(1) — constant extra space.
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before head to handle edge cases smoothly
        ListNode* result = new ListNode(0, head);
        ListNode* dummy = result;
        
        // Step 1: Move `head` pointer n steps ahead
        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        // Step 2: Move both pointers until `head` reaches the end
        while (head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }

        // Step 3: Remove the nth node from the end
        dummy->next = dummy->next->next;

        // Step 4: Return new head (skip dummy)
        ListNode* res = result->next;
        delete result; // free dummy node memory
        return res;
    }
};
