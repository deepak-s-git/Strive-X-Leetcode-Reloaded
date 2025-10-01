/*
Problem: Subtree of Another Tree (LeetCode #572)
------------------------------------------------
Given the roots of two binary trees `mainRoot` and `candidate`, return `true` 
if `candidate` is a **subtree** of `mainRoot`, otherwise return `false`.

A subtree of a tree `T` is a tree consisting of a node in `T` and all of its descendants.  
The subtree must match `candidate` exactly in **structure and node values**.

Example:
--------
Input:
mainRoot = [3,4,5,1,2], candidate = [4,1,2]

       3
      / \
     4   5
    / \
   1   2

       4
      / \
     1   2

Output: true

Explanation: The subtree rooted at node with value 4 matches `candidate`.

Constraints:
------------
- The number of nodes in both trees is in the range [0, 2000].
- -10⁴ <= Node.val <= 10⁴
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Recursion + Tree Comparison
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - To check if `candidate` is a subtree of `mainRoot`, we need to see if there exists
//   any node in `mainRoot` whose subtree is identical to `candidate`.
// - Use a helper `areIdentical()` to compare two trees node by node.
// - Recursively check every node in `mainRoot`.
//
// ⚙️ Steps:
// 1. Traverse `mainRoot`. At each node, check if `mainRoot` and `candidate` are identical.
// 2. If yes → return true.
// 3. Else → recursively check `mainRoot->left` and `mainRoot->right`.
//
// ⏱️ Time Complexity: O(N * M)  
//     - N = number of nodes in `mainRoot`
//     - M = number of nodes in `candidate`
// 📦 Space Complexity: O(H) (recursion depth, H = height of tree)
// -----------------------------------------------------------------------------

// ✅ Helper: Check if two trees are identical
bool areIdentical(TreeNode* nodeA, TreeNode* nodeB) {
    if (!nodeA && !nodeB) return true;         // both NULL → identical
    if (!nodeA || !nodeB) return false;        // one NULL → not identical

    return (nodeA->val == nodeB->val &&        // check current node
            areIdentical(nodeA->left, nodeB->left) &&    // check left
            areIdentical(nodeA->right, nodeB->right));   // check right
}

class Solution {
public:
    // 🚀 Main function: Check if `candidate` is a subtree of `mainRoot`
    bool isSubtree(TreeNode* mainRoot, TreeNode* candidate) {
        if (!mainRoot) return false;  // base: empty main tree can't contain a subtree
        if (areIdentical(mainRoot, candidate)) return true; // match found

        // 🔁 Recurse on left or right subtree
        return isSubtree(mainRoot->left, candidate) || 
               isSubtree(mainRoot->right, candidate);
    }
};
