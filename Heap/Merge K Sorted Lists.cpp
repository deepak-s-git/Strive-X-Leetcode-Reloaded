/*
Problem: Merge k Sorted Lists (LeetCode #23)
---------------------------------------------
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example:
--------
Input: 
lists = [[1,4,5],[1,3,4],[2,6]]

Output:
[1,1,2,3,4,4,5,6]

Constraints:
------------
- k == lists.length
- 0 <= k <= 10^4
- 0 <= lists[i].length <= 500
- -10^4 <= Node.val <= 10^4
- The linked-lists are sorted in ascending order.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Divide and Conquer (Merge Sort Style)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Merge pairs of lists recursively just like merge sort.
// - Each merge step combines two sorted linked lists in O(n).
// - This reduces the overall complexity compared to sequential merging.
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(N log k) — where N = total number of nodes
// - 📦 Space Complexity: O(log k) — recursion depth
// -----------------------------------------------------------------------------
class Solution {
public:
    // Merge two sorted linked lists
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->val < b->val) {
            a->next = mergeTwo(a->next, b);
            return a;
        } else {
            b->next = mergeTwo(a, b->next);
            return b;
        }
    }

    // Recursively merge all lists using divide and conquer
    ListNode* mergeAll(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = l + (r - l) / 2;
        ListNode* left = mergeAll(lists, l, mid);
        ListNode* right = mergeAll(lists, mid + 1, r);
        return mergeTwo(left, right);
    }

    // Main function: merge k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeAll(lists, 0, lists.size() - 1);
    }
};
