/*
Problem: Reorder List (LeetCode #143)
--------------------------------------
You are given the head of a singly linked list.  
Reorder the list as follows:

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

You must do this **in-place** without modifying the values in the nodes.

Examples:
---------
Input:  head = [1,2,3,4]
Output: [1,4,2,3]

Input:  head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
------------
- The number of nodes in the list is in the range [1, 5 * 10^4].
- -1000 <= Node.val <= 1000
*/


// ✅ Approach: Find Middle + Reverse Second Half + Merge
// ------------------------------------------------------
// Steps:
// 1. **Find the middle** of the list using slow-fast pointers.
// 2. **Reverse the second half** of the list.
// 3. **Merge the two halves** by alternating nodes.
//
// Why it works:
// - We split the list into two halves.
// - Reversing the second half makes it easy to "interleave" from both ends.
// - Merging them creates the reordered list.
//
// Time Complexity: O(n)    → Each step traverses the list once.
// Space Complexity: O(1)   → Done in-place with no extra data structures.
//
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // 🔹 Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 🔹 Step 2: Reverse the second half
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Split the list into two halves
        ListNode* prev = nullptr;

        while (secondHalf) {
            ListNode* nextNode = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = nextNode;
        }

        // 🔹 Step 3: Merge the two halves
        ListNode* firstHalf = head;
        ListNode* second = prev;

        while (second) {
            ListNode* next1 = firstHalf->next;
            ListNode* next2 = second->next;

            firstHalf->next = second;
            second->next = next1;

            firstHalf = next1;
            second = next2;
        }
    }
};
