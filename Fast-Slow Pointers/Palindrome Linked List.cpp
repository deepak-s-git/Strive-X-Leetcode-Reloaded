/*
Problem: Palindrome Linked List (LeetCode #234)
----------------------------------------------
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Examples:
---------
Input: head = [1,2,2,1]  
Output: true

Input: head = [1,2]  
Output: false

Constraints:
------------
- The number of nodes in the list is in the range [1, 10^5].
- 0 <= Node.val <= 9
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Copy to Array (Brute Force)
// -----------------------------------------------------------------------------
// Idea:
// - Copy all node values into a vector.
// - Use two-pointer technique to check if the array is a palindrome.
//
// Time Complexity: O(n)  
// Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> copy;

        // Step 1: Copy linked list into vector
        while (head != NULL) {
            copy.push_back(head->val);
            head = head->next;
        }

        // Step 2: Check palindrome using two-pointer approach
        int left = 0, right = copy.size() - 1;
        while (left < right) {
            if (copy[left] != copy[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};



// -----------------------------------------------------------------------------
// ✅ Approach 2: Reverse Second Half (Optimal, O(1) Space)
// -----------------------------------------------------------------------------
// Idea:
// 1. Use slow and fast pointers to reach the middle of the list.
// 2. Reverse the second half of the linked list.
// 3. Compare first half and reversed second half.
// 4. (Optional) Restore the list to its original form.
//
// Why it works:
// - Only reverse and compare second half, so space is O(1).
// - Handles both even and odd length lists naturally.
//
// Time Complexity: O(n)  
// Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Step 1: Find the middle using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // Step 3: Compare first half and reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
