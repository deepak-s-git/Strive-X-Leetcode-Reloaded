/*
Problem: Binary Tree Paths (LeetCode #257)
------------------------------------------
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example:
--------
Input: 
    1
   / \
  2   3
   \
    5

Output: ["1->2->5","1->3"]

Explanation:
- Path 1: 1 → 2 → 5
- Path 2: 1 → 3

Constraints:
------------
- The number of nodes in the tree is in the range [1, 100].
- -100 <= Node.val <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Approach: DFS + Backtracking (Top-Down Path Construction)
// -----------------------------------------------------------------------------
// Idea:
// - Perform a depth-first search (DFS) starting from the root.
// - Maintain a `path` string as you traverse the tree.
// - When you reach a leaf node (no left or right child), add the path to the result.
//
// Key Points:
// - At each step, append the current node value to the `path`.
// - If not a leaf, append "->" to continue building the path.
// - If leaf: push the complete path into the result list.
//
// Time Complexity: O(N²)  (due to string concatenation on each path)
// Space Complexity: O(H)  (H = height of tree, for recursion stack)
// -----------------------------------------------------------------------------
class Solution {
public:
    // Helper DFS function to explore all root-to-leaf paths
    void dfs(TreeNode* node, vector<string>& res, string path) {
        if (!node) return;  // base case: null node

        // If current node has children → append value and arrow
        if (node->left || node->right) {
            path += to_string(node->val) + "->";
        } 
        // If leaf node → complete the path and store it
        else {
            path += to_string(node->val);
            res.push_back(path);
        }

        // Explore left and right children
        dfs(node->left, res, path);
        dfs(node->right, res, path);
    }

    // Main function to return all root-to-leaf paths
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, res, "");  // start DFS with an empty path
        return res;
    }
};