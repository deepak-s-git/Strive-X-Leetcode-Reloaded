/*
Problem: Validate Binary Search Tree (LeetCode #98)
---------------------------------------------------
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as:
- The left subtree of a node contains only nodes with keys < node.val
- The right subtree of a node contains only nodes with keys > node.val
- Both left and right subtrees must also be BSTs.

Example:
--------
Input:
    2
   / \
  1   3

Output: true

Input:
    5
   / \
  1   4
     / \
    3   6

Output: false
Explanation: The node with value 4 has a left child with value 3, which is not > 5.

Constraints:
------------
- The number of nodes in the tree is in the range [1, 10^4].
- -2^31 <= Node.val <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Inorder Traversal (BST Property Check)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - The inorder traversal of a BST should always produce a strictly increasing sequence.
// - Perform an inorder traversal and keep track of the last visited node.
// - If at any point the current node's value ≤ last visited node's value, the tree is invalid.
//
// ⏱️ Time Complexity: O(N) — visit every node once
// 📦 Space Complexity: O(H) — recursion stack (H = height of tree)
// -----------------------------------------------------------------------------
class Solution {
private:
    TreeNode* lastVisited;  // Keeps track of the previous node during inorder traversal

    bool inorder(TreeNode* node) {
        if (!node) return true;

        // Traverse left subtree
        if (!inorder(node->left)) return false;

        // Check BST property
        if (lastVisited && node->val <= lastVisited->val) return false;
        lastVisited = node;

        // Traverse right subtree
        return inorder(node->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        lastVisited = nullptr; // Initialize previous node as null
        return inorder(root);
    }
};
