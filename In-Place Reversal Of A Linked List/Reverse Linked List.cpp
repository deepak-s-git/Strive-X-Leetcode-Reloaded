/*
🔁 Problem: Reverse Linked List (LeetCode 206)

Given the head of a singly linked list, reverse the list, and return the new head.

📥 Example:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

📥 Example 2:
Input: head = [1,2]
Output: [2,1]

📥 Example 3:
Input: head = []
Output: []

⚙️ Constraints:
- The number of nodes in the list is in the range [0, 5000].
- -5000 <= Node.val <= 5000
*/


/* ================================================================
   ✅ Approach 1: Iterative Pointer Reversal
   ================================================================
   🔍 Intuition:
   - We iteratively reverse the direction of `next` pointers.
   - Keep track of the previous node (`node`) and the current node (`head`).
   - Temporarily store the next node before breaking the link.

   🧩 Steps:
   1. Initialize `node = nullptr`
   2. For each node, store next → reverse link → move forward.

   ⏱️ Complexity:
   - Time:  O(n)
   - Space: O(1)
================================================================ */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;  // Save next node
            head->next = node;            // Reverse link
            node = head;                  // Move prev forward
            head = temp;                  // Move head forward
        }

        return node;        
    }
};


/* ================================================================
   ✅ Approach 2: Recursive Reversal
   ================================================================
   🔍 Intuition:
   - Recursively reverse the rest of the list and fix the current node’s link.
   - The recursion stack naturally handles the backtracking to reverse connections.

   🧩 Steps:
   1. Base case: if list empty or one node → return head.
   2. Recursively reverse the sublist.
   3. Fix the pointers: `head->next->next = head; head->next = nullptr`.

   ⏱️ Complexity:
   - Time:  O(n)
   - Space: O(n)  (recursion stack)
================================================================ */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;  // Reverse the link
        head->next = nullptr;     // Break old connection

        return newHead;        
    }
};
