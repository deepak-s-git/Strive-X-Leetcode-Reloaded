/*
Problem: Maximum Binary Tree (LeetCode #654)
--------------------------------------------
Given an integer array `a` with no duplicates, you need to construct a **Maximum Binary Tree**:

- The root is the maximum number in the array.
- The left subtree is the maximum tree constructed from the left subarray.
- The right subtree is the maximum tree constructed from the right subarray.

Example:
--------
Input: a = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]

Explanation:
- The maximum number is 6, so it becomes the root.
- Left subtree is built from [3,2,1]
- Right subtree is built from [0,5]

Constraints:
------------
- 1 <= a.length <= 1000
- 0 <= a[i] <= 1000
- All elements of `a` are unique.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Recursive Divide and Conquer
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Find the maximum element in the current range → root node.
// - Recursively construct the left subtree from the subarray left to the max element.
// - Recursively construct the right subtree from the subarray right to the max element.
//
// ⏱️ Time Complexity: O(N^2) worst case (sorted input, each call scans subarray)
// 📦 Space Complexity: O(N) recursion stack (height of tree in worst case)
// -----------------------------------------------------------------------------
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        return build(a, 0, a.size() - 1);
    }

private:
    TreeNode* build(vector<int>& a, int l, int r) {
        if (l > r) return nullptr;

        int idx = l, mx = a[l];
        for (int i = l; i <= r; i++) {
            if (a[i] > mx) {
                mx = a[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(mx);
        root->left = build(a, l, idx - 1);
        root->right = build(a, idx + 1, r);

        return root;
    }
};
