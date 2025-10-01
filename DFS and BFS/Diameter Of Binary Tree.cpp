/*
Problem: Diameter of Binary Tree (LeetCode #543)
------------------------------------------------
Given the `root` of a binary tree, return the **diameter** of the tree.

- The diameter is the **length of the longest path** between any two nodes.
- The path may or may not pass through the root.
- The length of a path is the number of **edges** between nodes.

Example:
--------
Input: root = [1,2,3,4,5]  
Output: 3  
Explanation: The longest path is 4 → 2 → 1 → 3 or 5 → 2 → 1 → 3

Constraints:
------------
- The number of nodes in the tree is in the range [1, 10⁴]
- -100 <= Node.val <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Optimized Approach: DFS (Post-order Traversal)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Diameter = longest path = leftDepth + rightDepth for some node.
// - At each node:
//    - Find depth of left and right subtrees.
//    - Update `maxDiameter` as `leftDepth + rightDepth` (edges count).
// - Return the depth to the parent (1 + max(left, right)).
//
// ⚙️ Steps:
// 1. Use a helper DFS function to compute subtree depths.
// 2. Update the global diameter while returning depths.
// 3. Final diameter is the max path found.
//
// ⏱️ Time Complexity: O(N) – each node is visited once  
// 📦 Space Complexity: O(H) – recursion depth (H = height of tree)
// -----------------------------------------------------------------------------

class Solution {
    int maxDiameter = 0;  // 📊 Stores the maximum diameter found so far

public:
    int diameterOfBinaryTree(TreeNode* rootNode) {
        calculateDepth(rootNode);    // 🌲 Start DFS traversal
        return maxDiameter;          // ✅ Final diameter (in edges)
    }

private:
    // 📏 Helper: returns depth of subtree rooted at `node`
    int calculateDepth(TreeNode* node) {
        if (!node) return 0; // ✅ Base case: empty subtree

        // 🔁 Recurse for left and right depths
        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);

        // 📈 Update max diameter if current path is longer
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        // 📤 Return current depth to parent node
        return 1 + max(leftDepth, rightDepth);
    }
};
