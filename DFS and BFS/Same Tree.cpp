/*
Problem: Same Tree (LeetCode #100)
----------------------------------
Given the roots of two binary trees `p` and `q`, write a function to check if they are the same.

- Two binary trees are considered the same if they are structurally identical
  and the nodes have the same value.

Example:
--------
Input: 
p = [1,2,3], q = [1,2,3]
Output: true

Input: 
p = [1,2], q = [1,null,2]
Output: false

Constraints:
------------
- The number of nodes in both trees is in the range [0, 100].
- -10^4 <= Node.val <= 10^4
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Recursive DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Recursively compare both trees node by node.
// - At each step:
//   1. If both nodes are NULL → they are the same (✅ base case).
//   2. If one is NULL and the other is not → not the same.
//   3. If values are equal → recursively check left and right subtrees.
//
// ⏱️ Time Complexity: O(N) – visit each node once.
// 📦 Space Complexity: O(H) – recursion depth (H = height of tree).
// -----------------------------------------------------------------------------
class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        // ✅ Case 1: Both are NULL → same
        if (!root1 && !root2) {
            return true;
        }

        // ✅ Case 2: Both exist and values match → check subtrees
        if (root1 && root2 && root1->val == root2->val) {
            return isSameTree(root1->left, root2->left) &&   // check left subtree
                   isSameTree(root1->right, root2->right);  // check right subtree
        }

        // ❌ Case 3: One is NULL or values don't match
        return false;
    }
};
