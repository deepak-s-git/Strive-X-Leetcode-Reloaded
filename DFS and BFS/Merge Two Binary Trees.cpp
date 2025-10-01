/*
Problem: Merge Two Binary Trees (LeetCode #617)
----------------------------------------------
You are given the roots of two binary trees `t1` and `t2`.

- Merge them into a single tree by **adding the values** of overlapping nodes.
- If a node exists in only one tree, use that node directly.

Example:
--------
Input: 
   Tree 1:        1            Tree 2:        2
                 / \                         / \
                3   2                       1   3
               /                             \   \
              5                               4   7

Output (Merged Tree):
                     3
                   /   \
                  4     5
                 / \     \
                5   4     7

Constraints:
------------
- The number of nodes in both trees is in the range [0, 2000].
- -10⁴ <= Node.val <= 10⁴
*/


// -----------------------------------------------------------------------------
// ✅ Recursive DFS Approach (Top-Down)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Traverse both trees simultaneously.
// - If both nodes exist → sum values.
// - If one node is NULL → use the other as it is.
//
// ⚙️ Steps:
// 1. If `t1` is NULL → return `t2`.
// 2. If `t2` is NULL → return `t1`.
// 3. Update `t1->val` += `t2->val`.
// 4. Recursively merge left and right children.
//
// ⏱️ Time Complexity: O(N) – visits each node once  
// 📦 Space Complexity: O(H) – recursion depth (H = height of tree)
// -----------------------------------------------------------------------------

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 🪵 Base cases
        if (!t1) return t2;   // If t1 is empty → use t2
        if (!t2) return t1;   // If t2 is empty → use t1

        // ➕ Merge node values
        t1->val += t2->val;

        // 🔁 Recurse for left & right children
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1; // ✅ Return merged tree
    }
};
