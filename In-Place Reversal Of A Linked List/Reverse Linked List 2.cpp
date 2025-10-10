/*
🔁 Problem: Reverse Linked List II (LeetCode 92)

Given the head of a singly linked list and two integers `left` and `right`
where `left <= right`, reverse the nodes of the list from position `left` 
to `right`, and return the reversed list.

📥 Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4  
Output: [1,4,3,2,5]

📥 Example 2:
Input: head = [5], left = 1, right = 1  
Output: [5]

⚙️ Constraints:
- The number of nodes in the list is in the range [1, 500].
- -500 <= Node.val <= 500
- 1 <= left <= right <= n
*/


/* ================================================================
   ✅ Approach: In-place Sublist Reversal
   ================================================================
   🔍 Intuition:
   - Reverse only the portion between `left` and `right` while keeping 
     the rest of the list intact.
   - Use a dummy node to simplify handling when `left = 1`.

   🧩 Steps:
   1. Move a pointer to the node just before `left` (call it `beforeLeft`).
   2. Perform an in-place reversal between `left` and `right` using pointer swapping.
   3. Connect the reversed segment back to the main list.

   🧠 Example:
   head = [1,2,3,4,5], left = 2, right = 4

   Step-by-step reversal:
   1 → 2 → 3 → 4 → 5  
   becomes  
   1 → 4 → 3 → 2 → 5

   ⏱️ Complexity:
   - Time:  O(n)
   - Space: O(1)
================================================================ */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* beforeLeft = dummyNode;

        // Step 1️⃣: Move beforeLeft to node before 'left'
        for (int i = 0; i < left - 1; i++) {
            beforeLeft = beforeLeft->next;
        }

        // Step 2️⃣: Start of the sublist to reverse
        ListNode* startNode = beforeLeft->next;

        // Step 3️⃣: Reverse nodes between left and right
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = startNode->next;
            startNode->next = nextNode->next;
            nextNode->next = beforeLeft->next;
            beforeLeft->next = nextNode;
        }

        return dummyNode->next;
    }
};
