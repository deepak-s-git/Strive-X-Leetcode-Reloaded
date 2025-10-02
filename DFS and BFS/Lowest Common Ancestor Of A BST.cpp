/*
Problem: Lowest Common Ancestor of a BST (LeetCode #235)
---------------------------------------------------------
Given a binary search tree (BST) and two nodes `node1` and `node2`, 
find their lowest common ancestor (LCA). 

Example:
--------
Input: root = [6,2,8,0,4,7,9,null,null,3,5], node1 = 2, node2 = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], node1 = 2, node2 = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself.

Constraints:
------------
- All node values are unique.
- Both `node1` and `node2` exist in the BST.
- Number of nodes in the tree is in the range [2, 10^5].
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Iterative BST Traversal
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - In a BST, all values in the left subtree < root < all values in the right subtree.
// - Start at root and traverse down:
//   1. If both nodes are greater than current, LCA is in the right subtree.
//   2. If both nodes are smaller than current, LCA is in the left subtree.
//   3. Otherwise, current node is the LCA.
//
// ⏱️ Time Complexity: O(H), H = height of BST
// 📦 Space Complexity: O(1), iterative
// -----------------------------------------------------------------------------
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        while (root) {
            if (node1->val > root->val && node2->val > root->val) {
                root = root->right;       // move right
            } else if (node1->val < root->val && node2->val < root->val) {
                root = root->left;        // move left
            } else {
                return root;              // split point → LCA
            }
        }
        return nullptr;
    }
};


// -----------------------------------------------------------------------------
// ✅ Alternative Iterative Style
// -----------------------------------------------------------------------------
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* n1, TreeNode* n2) {
        while (node) {
            if (min(n1->val, n2->val) > node->val) {
                node = node->right;
            } else if (max(n1->val, n2->val) < node->val) {
                node = node->left;
            } else {
                return node;  // LCA found
            }
        }
        return nullptr;        
    }
};
