/*
Problem: Lowest Common Ancestor of a Binary Tree (LeetCode #236)
-----------------------------------------------------------------
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes `x` and `y`.

The LCA of two nodes is defined as the lowest node in the tree that has both `x` and `y` 
as descendants (where we allow a node to be a descendant of itself).

Example:
--------
Input: 
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

x = 5, y = 1
Output: 3

Explanation: The LCA of nodes 5 and 1 is 3.

Constraints:
------------
- The number of nodes in the tree is in the range [2, 10^5].
- All Node values are unique.
- x and y will exist in the tree.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Recursive DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - If the current node is NULL or equals one of the target nodes (x or y), 
//   return the current node.
// - Recurse into left and right subtrees.
// - If both sides return non-null, this node is the LCA.
// - If only one side returns non-null, propagate that result upward.
//
// ⏱️ Time Complexity: O(N) — each node is visited once.
// 📦 Space Complexity: O(H) — recursion stack (H = height of tree).
// -----------------------------------------------------------------------------
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
        if (!root || root == x || root == y) return root;

        TreeNode* l = lowestCommonAncestor(root->left, x, y);
        TreeNode* r = lowestCommonAncestor(root->right, x, y);

        if (l && r) return root;   // 🔥 x and y found in different subtrees
        return l ? l : r;          // 🔁 return non-null side (LCA deeper down)
    }
};
