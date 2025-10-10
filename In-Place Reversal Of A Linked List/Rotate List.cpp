/*
🔁 Problem: Rotate List (LeetCode 61)

Given the head of a linked list, rotate the list to the right by `k` places.

📥 Example 1:
Input: head = [1,2,3,4,5], k = 2  
Output: [4,5,1,2,3]

📥 Example 2:
Input: head = [0,1,2], k = 4  
Output: [2,0,1]

⚙️ Constraints:
- The number of nodes in the list is in the range [0, 500].
- -100 <= Node.val <= 100
- 0 <= k <= 2 * 10⁹
*/


/* ================================================================
   ✅ Approach: Two-Pass Linked List Traversal
   ================================================================
   🔍 Intuition:
   - Rotating the list by `k` means moving the last `k` nodes to the front.
   - Example:
       [1 → 2 → 3 → 4 → 5], k = 2  
       → [4 → 5 → 1 → 2 → 3]
   - We can achieve this by:
       1️⃣ Finding the total length of the list.
       2️⃣ Linking the tail to the head (forming a circular list).
       3️⃣ Breaking the link at the new tail position.

   🧠 Steps:
   1. Find the length of the list (`listLength`) and locate the tail node.
   2. Compute `rotationSteps = k % listLength` (since rotating by `listLength` = no change).
   3. Find the new tail node: `(listLength - rotationSteps - 1)` from the start.
   4. Set `newHead = newTail->next`, break the circle, and return `newHead`.

   ⏱️ Complexity:
   - Time:  O(n) — two passes through the list.
   - Space: O(1) — constant extra memory.
================================================================ */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;  // Empty list check
        
        // Step 1️⃣: Find length and tail node
        int listLength = 1;
        ListNode* tailNode = head;
        while (tailNode->next) {
            tailNode = tailNode->next;
            listLength++;
        }

        // Step 2️⃣: Find effective rotations
        int rotationSteps = k % listLength;
        if (rotationSteps == 0) return head;  // No rotation needed

        // Step 3️⃣: Find new tail (listLength - rotationSteps - 1)
        ListNode* newTail = head;
        for (int i = 0; i < listLength - rotationSteps - 1; ++i) {
            newTail = newTail->next;
        }

        // Step 4️⃣: Rearrange pointers
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tailNode->next = head;

        return newHead;
    }
};
