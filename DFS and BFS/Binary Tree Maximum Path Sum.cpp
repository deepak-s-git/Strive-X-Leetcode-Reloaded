/*
Problem: Binary Tree Maximum Path Sum (LeetCode #124)
------------------------------------------------------
Given the root of a binary tree, return the maximum path sum of any **non-empty path**.

A path is defined as any sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.  
A node can only appear once in the path, and it **does not have to pass through the root**.

Example 1:
----------
Input:
       1
      / \
     2   3

Output: 6
Explanation: The maximum path is [2 -> 1 -> 3] with a sum of 6.

Example 2:
----------
Input:
      -10
      /  \
     9   20
        /  \
       15   7

Output: 42
Explanation: The maximum path is [15 -> 20 -> 7] with a sum of 42.

Constraints:
------------
- The number of nodes in the tree is in the range [1, 3 * 10^4].
- -1000 <= Node.val <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: DFS + Postorder Traversal (Global Max Tracking)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - The max path at any node could be one of the following:
//   1. Node + left subtree path
//   2. Node + right subtree path
//   3. Node + left + right subtree paths (path passing through this node)
//
// - Use DFS to recursively compute the **max gain** from left and right subtrees.
// - At each node:
//   - Ignore negative sums (because they reduce total path sum).
//   - Update the global `maxSum` with `leftMax + rightMax + node->val` (path through node).
//   - Return `node->val + max(leftMax, rightMax)` (max single-branch gain upwards).
//
// ⏱️ Time Complexity: O(N) — Visit each node once
// 📦 Space Complexity: O(H) — Recursion stack (H = height of tree)
// -----------------------------------------------------------------------------
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;          // Global maximum path sum
        dfs(root, maxSum);
        return maxSum;
    }

private:
    // 🔁 DFS returns the max path sum that can be extended upwards from this node
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // 🚫 Ignore negative paths (take 0 if subtree is negative)
        int leftMax = max(0, dfs(node->left, maxSum));
        int rightMax = max(0, dfs(node->right, maxSum));

        // ✅ Check if passing through this node gives a better max path
        maxSum = max(maxSum, leftMax + rightMax + node->val);

        // 🔁 Return the best single-branch path sum (to continue upwards)
        return max(leftMax, rightMax) + node->val;
    }
};
