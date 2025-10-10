/*
🔁 Problem: Odd Even Linked List (LeetCode 328)

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,  
and return the reordered list.

⚠️ Note:
- The first node is considered odd, and the second node is even, and so on.
- Try to do it in-place with O(1) extra space.

📥 Example 1:
Input: head = [1,2,3,4,5]  
Output: [1,3,5,2,4]

📥 Example 2:
Input: head = [2,1,3,5,6,4,7]  
Output: [2,3,6,7,1,5,4]

⚙️ Constraints:
- The number of nodes in the list is in the range [0, 10^4].
- -10^6 <= Node.val <= 10^6
*/


/* ================================================================
   ✅ Approach: Two-Pointer Reordering
   ================================================================
   🔍 Intuition:
   - Maintain two separate linked lists:
       1️⃣ Odd-indexed nodes.
       2️⃣ Even-indexed nodes.
   - Traverse the list, connecting odd nodes together and even nodes together.
   - Finally, connect the end of the odd list to the start of the even list.

   🧠 Step-by-Step:
   - Initialize pointers:
       - `oddPointer` → start of odd list (head)
       - `evenPointer` → start of even list (head->next)
       - `evenStart` → to reconnect even list later.
   - Traverse while `evenPointer` and `evenPointer->next` exist.
       - Link odd to next odd, even to next even.
   - Finally, attach `oddPointer->next` to the start of even list.

   ⏱️ Complexity:
   - Time:  O(n) — one pass through all nodes.
   - Space: O(1) — only pointers used, no extra storage.
================================================================ */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1️⃣: Initialize pointers
        ListNode* oddPointer = head;
        ListNode* evenPointer = head->next;
        ListNode* evenStart = evenPointer;

        // Step 2️⃣: Rearrange nodes in one traversal
        while (evenPointer && evenPointer->next) {
            oddPointer->next = evenPointer->next;
            oddPointer = oddPointer->next;
            evenPointer->next = oddPointer->next;
            evenPointer = evenPointer->next;
        }

        // Step 3️⃣: Connect odd list to even list
        oddPointer->next = evenStart;

        // Step 4️⃣: Return rearranged list
        return head;
    }
};
