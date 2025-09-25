/*
Problem: Sort List (LeetCode #148)
----------------------------------
Given the head of a linked list, return the list after sorting it 
in ascending order.

Examples:
---------
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Constraints:
------------
- The number of nodes in the list is in the range [0, 5 * 10^4].
- -10^5 <= Node.val <= 10^5
*/


// -----------------------------------------------------------------------------
// ❌ Approach 1: Brute Force (Using Extra Space)
// -----------------------------------------------------------------------------
// Idea:
// - Traverse the linked list and store all values in a vector.
// - Sort the vector.
// - Reassign the sorted values back to the linked list.
//
// Pros: Simple and easy to implement.
// Cons: Uses O(n) extra space and breaks the linked list structure.
// 
// Time Complexity: O(n log n)   (sorting vector)
// Space Complexity: O(n)        (storing values separately)
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;

        // Step 1: Store all node values in a vector
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Sort the vector
        sort(v.begin(), v.end());

        // Step 3: Rewrite sorted values back to the linked list
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = v[i++];
            temp = temp->next;
        }

        return head;
    }
};



// -----------------------------------------------------------------------------
// ✅ Approach 2: Merge Sort on Linked List (Optimal, O(1) Space)
// -----------------------------------------------------------------------------
// Idea:
// - Use Merge Sort (Divide & Conquer):
//   1. Split the linked list into two halves using slow-fast pointers.
//   2. Recursively sort both halves.
//   3. Merge the two sorted halves.
// 
// Why Merge Sort?
// - Works efficiently with linked lists since we don’t need random access.
// - Preserves O(1) extra space (no arrays/vectors).
//
// Time Complexity: O(n log n)  (log n splits, n merges)
// Space Complexity: O(1)       (no extra containers used except recursion stack)
// -----------------------------------------------------------------------------
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 node is already sorted
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Step 1: Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        // Step 2: Sort each half recursively
        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);

        // Step 3: Merge the sorted halves
        return merge(left, right);
    }

private:
    // Helper function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining part
        tail->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};
