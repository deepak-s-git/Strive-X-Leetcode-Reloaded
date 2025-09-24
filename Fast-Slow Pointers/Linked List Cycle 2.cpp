/*
Problem: Linked List Cycle II (LeetCode #142)
--------------------------------------------
Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return `nullptr`.

Examples:
---------
Input: head = [3,2,0,-4], pos = 1  
Output: tail connects to node index 1

Input: head = [1,2], pos = 0  
Output: tail connects to node index 0

Input: head = [1], pos = -1  
Output: no cycle

Constraints:
------------
- The number of nodes in the list is in the range [0, 10⁴].
- -10⁵ <= Node.val <= 10⁵
- `pos` is -1 or a valid index indicating the start of the cycle.
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Hash Set (Easy but O(n) Space)
// -----------------------------------------------------------------------------
// - Traverse the list and store each visited node in a hash set.
// - If a node repeats, it's the start of the cycle.
// - If traversal ends (nullptr), no cycle exists.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;  // store visited nodes

        while (head) {
            if (visited.find(head) != visited.end()) {
                return head;  // cycle starts here
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;  // no cycle
    }
};



// -----------------------------------------------------------------------------
// ✅ Approach 2: Floyd’s Tortoise and Hare (O(1) Space)
// -----------------------------------------------------------------------------
// Idea:
// 1. Use two pointers (slow and fast):
//    - slow moves 1 step, fast moves 2 steps.
//    - If they meet, a cycle exists.
// 2. Reset one pointer to head, then move both one step at a time.
//    - The point where they meet again is the **start of the cycle**.
//
// Why this works:
// - Meeting point is `k` steps from the cycle start due to modular properties
//   of cycle traversal (mathematical proof of Floyd’s algorithm).
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps
            
            if (slow == fast) {          // cycle detected
                isCycle = true;
                break;
            }
        }

        if (!isCycle) return NULL;       // no cycle present

        // Step 2: Find the start of the cycle
        slow = head;                     // reset slow to head
        while (slow != fast) {           // move both 1 step
            slow = slow->next;
            fast = fast->next;
        }

        return slow;                     // start of the cycle
    }
};
