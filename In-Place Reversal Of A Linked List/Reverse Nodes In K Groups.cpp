/*
🔁 Problem: Reverse Nodes in k-Group (LeetCode 25)

Given a linked list, reverse the nodes of the list *k* at a time and return its modified list.  
*k* is a positive integer and is less than or equal to the length of the linked list.  
If the number of nodes is not a multiple of *k*, the remaining nodes are left as is.

⚠️ Note:
- You may not alter the values in the list’s nodes, only nodes themselves may be changed.

📥 Example 1:
Input: head = [1,2,3,4,5], k = 2  
Output: [2,1,4,3,5]

📥 Example 2:
Input: head = [1,2,3,4,5], k = 3  
Output: [3,2,1,4,5]

⚙️ Constraints:
- The number of nodes in the list is in the range [1, 5000].
- 0 <= Node.val <= 1000
- 1 <= k <= 5000
*/


/* ================================================================
   ✅ Approach: Recursive Reversal in Groups of K
   ================================================================
   🔍 Intuition:
   - First, check if there are at least *k* nodes available for reversal.
   - If not, return the current head (no change).
   - Otherwise:
       1️⃣ Move *k* steps forward to find the sublist to reverse.
       2️⃣ Recursively reverse the rest of the list starting from the (k+1)th node.
       3️⃣ Reverse the current group of k nodes.
       4️⃣ Link the reversed group to the previously reversed part.

   🧠 Step-by-Step:
   - Traverse k nodes ahead using `temp`.
   - If there aren’t enough nodes, just return `head`.
   - Recursively call `reverseKGroup(temp, k)` for the next part of the list.
   - Reverse the first k nodes and connect to the recursively processed remainder.

   ⏱️ Complexity:
   - Time:  O(n) — each node is visited once.
   - Space: O(n/k) — due to recursion stack.
================================================================ */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Step 1️⃣: Check if there are at least k nodes to reverse
        while (cnt < k) {
            if (temp == NULL) {
                return head;  // Less than k nodes — return as is
            }
            temp = temp->next;
            cnt++;
        }

        // Step 2️⃣: Recursively reverse the rest of the list
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3️⃣: Reverse current k nodes
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;
            cnt++;
        }

        // Step 4️⃣: Return new head of this reversed segment
        return prevNode;
    }
};
