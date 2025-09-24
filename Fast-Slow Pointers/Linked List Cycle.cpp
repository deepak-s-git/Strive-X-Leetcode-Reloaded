/*
Problem: Linked List Cycle (LeetCode #141)
------------------------------------------
Given the head of a linked list, determine if the linked list has a cycle.  
A cycle exists if there is a node that can be reached again by continuously 
following the `next` pointer.

Examples:
---------
Input: head = [3,2,0,-4], pos = 1  
Output: true  
Explanation: There is a cycle linking the last node to index 1.

Input: head = [1,2], pos = 0  
Output: true

Input: head = [1], pos = -1  
Output: false

Constraints:
------------
- The number of nodes in the list is in the range [0, 10^4].
- -10^5 <= Node.val <= 10^5
- `pos` is -1 if there is no cycle, else the index of the node where the tail connects.
*/


// -----------------------------------------------------------------------------
// Approach: Floyd's Tortoise and Hare Algorithm (Two Pointers)
// -----------------------------------------------------------------------------
// Idea:
// 1. Use two pointers: `slow` (moves 1 step) and `fast` (moves 2 steps).
// 2. If there's a cycle, they will eventually meet inside the loop.
// 3. If `fast` reaches NULL (end of list), no cycle exists.
//
// Why this works:
// - In a cyclic linked list, the faster pointer will "lap" the slower one.
// - If the list is acyclic, `fast` will reach the end.
//
// Time Complexity: O(n)  
// Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Base case: empty list or single node cannot form a cycle
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode* slow = head;  // moves 1 step
        ListNode* fast = head;  // moves 2 steps

        // Traverse the list with two pointers
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // If they meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }

        // Fast pointer reached the end => no cycle
        return false;
    }
};
