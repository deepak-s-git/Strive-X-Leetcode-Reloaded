/*
Problem: Invert Binary Tree (LeetCode #226)
-------------------------------------------
Given the root of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping every left child with its right child.

Example:
--------
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Constraints:
------------
- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Recursive DFS (Post-order Traversal)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - At each node, simply swap its left and right child pointers.
// - Then recursively invert the left and right subtrees.
//
// ⚙️ Steps:
// 1. Base case: If the tree is empty (root == nullptr), return nullptr.
// 2. Swap `root->left` and `root->right`.
// 3. Recursively invert the left and right subtrees.
// 4. Return the root node.
//
// ⏱️ Time Complexity: O(N) – visit every node once.
// 📦 Space Complexity: O(H) – recursion stack (H = height of tree).
// -----------------------------------------------------------------------------

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;  // ✅ Base case: empty tree
        }

        // 🔄 Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 🔁 Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;  // ✅ Return the inverted root node
    }
};
