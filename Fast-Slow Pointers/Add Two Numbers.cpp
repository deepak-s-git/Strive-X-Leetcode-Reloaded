/*
Problem: Add Two Numbers (LeetCode #2)
--------------------------------------
You are given two non-empty linked lists representing two non-negative integers.  
The digits are stored in reverse order, and each of their nodes contains a single digit.  
Add the two numbers and return the sum as a linked list.

Examples:
---------
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
------------
- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number without leading zeros.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Simulation with Carry (Elementary Addition)
// -----------------------------------------------------------------------------
// Idea:
// - Traverse both lists simultaneously, adding corresponding digits + carry.
// - Create new nodes for the result linked list as we go.
// - If one list is shorter, treat missing digits as 0.
// - If there's a leftover carry at the end, add a final node.
//
// Why this works:
// - This is identical to how we add numbers by hand (column-wise addition).
//
// Time Complexity: O(max(m, n)) — where m and n are lengths of l1 and l2.
// Space Complexity: O(max(m, n)) — for the result list.
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // dummy node to simplify result construction
        ListNode* tail = dummyHead;            // pointer to build the result list
        int carry = 0;                         // store carry after each addition
        
        // Traverse both lists until all digits and carry are processed
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0; // get digit from l1
            int digit2 = (l2 != nullptr) ? l2->val : 0; // get digit from l2

            int sum = digit1 + digit2 + carry;          // add digits + carry
            int digit = sum % 10;                      // result digit
            carry = sum / 10;                          // update carry

            // create a new node with the result digit
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;                      // link it to result list
            tail = tail->next;                         // move tail forward

            // move to next nodes in l1 and l2 if available
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // result is stored in dummyHead->next (skip dummy node)
        ListNode* res = dummyHead->next;
        delete dummyHead; // free dummy node
        return res;
    }
};
