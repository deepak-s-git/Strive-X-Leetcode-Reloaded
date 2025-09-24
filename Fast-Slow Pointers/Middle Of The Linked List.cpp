/*
Problem: Middle of the Linked List (LeetCode #876)
--------------------------------------------------
Given the head of a singly linked list, return the middle node of the linked list.  
If there are two middle nodes, return the second middle node.

Examples:
---------
Input: head = [1,2,3,4,5]  
Output: [3,4,5]  
Explanation: The middle node is 3.

Input: head = [1,2,3,4,5,6]  
Output: [4,5,6]  
Explanation: Since there are two middle nodes (3 and 4), return the second one.

Constraints:
------------
- The number of nodes in the list is in the range [1, 100].
- 1 <= Node.val <= 100
*/


// -----------------------------------------------------------------------------
// Approach: Floyd’s Slow and Fast Pointer Technique
// -----------------------------------------------------------------------------
// Idea:
// - Use two pointers: `slow` moves 1 step, `fast` moves 2 steps.
// - When `fast` reaches the end, `slow` will be at the middle.
//
// Why it works:
// - For odd-length lists: `slow` lands exactly on the middle.
// - For even-length lists: `slow` lands on the second middle (as required).
//
// Time Complexity: O(n)  
// Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Base case: empty list or single node
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slow = head; // moves 1 step
        ListNode* fast = head; // moves 2 steps

        // Move fast and slow until fast reaches the end
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // `slow` is now at the middle node
        return slow;
    }
};
