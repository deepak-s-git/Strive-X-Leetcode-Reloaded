/*
🔁 Problem: Swap Nodes in Pairs (LeetCode 24)

Given a linked list, swap every two adjacent nodes and return its head.  
You must solve the problem without modifying the values in the list’s nodes.

📥 Example 1:
Input: head = [1,2,3,4]  
Output: [2,1,4,3]

📥 Example 2:
Input: head = []  
Output: []

📥 Example 3:
Input: head = [1]  
Output: [1]

⚙️ Constraints:
- The number of nodes in the list is in the range [0, 100].
- 0 <= Node.val <= 100
*/


/* ================================================================
   ✅ Approach: Iterative Pair Swapping
   ================================================================
   🔍 Intuition:
   - We want to swap each consecutive pair of nodes:  
     [1 → 2 → 3 → 4] → [2 → 1 → 4 → 3].
   - To do this without recursion:
     1️⃣ Use a dummy node pointing to the head for easier manipulation.
     2️⃣ Swap nodes `cur` and `cur->next` in pairs.
     3️⃣ Keep track of the previous node (`prev`) to re-link properly.

   🧠 Step-by-Step:
   - Use `dummy` → a sentinel node before the head.
   - Loop while both `cur` and `cur->next` exist.
   - Perform swapping:
       - `second->next = cur`
       - `cur->next = npn`  (where `npn` = next pair’s first node)
       - `prev->next = second`
   - Move `prev` and `cur` forward to process the next pair.

   ⏱️ Complexity:
   - Time:  O(n) — each node visited once.
   - Space: O(1) — in-place swapping, no extra space.
================================================================ */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Step 1️⃣: Dummy node simplifies head swapping
        ListNode dummy(0, head);
        ListNode *prev = &dummy, *cur = head;

        // Step 2️⃣: Iterate through pairs
        while (cur && cur->next) {
            ListNode *npn = cur->next->next;  // Next pair's start
            ListNode *second = cur->next;     // Second node in current pair

            // Step 3️⃣: Swap the pair
            second->next = cur;
            cur->next = npn;
            prev->next = second;

            // Step 4️⃣: Move to next pair
            prev = cur;
            cur = npn;
        }

        // Step 5️⃣: Return new head
        return dummy.next;        
    }
};
