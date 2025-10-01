/*
Problem: Minimum Depth of Binary Tree (LeetCode #111)
-----------------------------------------------------
Given a binary tree, find its minimum depth.

- The minimum depth is the number of nodes along the shortest path 
  from the root node down to the nearest leaf node.
- A leaf is a node with no children.

Example:
--------
Input: root = [3,9,20,null,null,15,7]
Output: 2
Explanation: The minimum depth is 2 (3 → 9).

Constraints:
------------
- The number of nodes in the tree is in the range [0, 10^5].
- -1000 <= Node.val <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: BFS (Level Order Traversal)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - We traverse the tree level by level (BFS).
// - The first time we encounter a leaf node (node with no children),
//   we immediately return the current depth, as BFS ensures it's the minimum depth.
//
// ⚙️ Steps:
// 1. Use a queue for level-order traversal.
// 2. Start from the root and track the current level.
// 3. For each node, if it's a leaf → return current level (minimum depth found).
// 4. Otherwise, push its children into the queue and continue.
//
// ⏱️ Time Complexity: O(N) – visit each node once.
// 📦 Space Complexity: O(N) – queue stores nodes at the current level.
// -----------------------------------------------------------------------------
class Solution {
public:
    int level = 0;

    int minDepth(TreeNode* root) {
        if (!root) return 0;  // ✅ Edge case: empty tree
        
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        // 🔁 BFS traversal
        while (!q.empty()) {
            int breadth = q.size();  // nodes at current level
            level++;                 // increment depth for this level

            // Process all nodes in this level
            for (int i = 0; i < breadth; i++) {
                TreeNode* parent = q.front();
                q.pop();

                // ✅ If leaf node → minimum depth found
                if (!parent->left && !parent->right)
                    return level;

                // 📥 Push children for next level
                if (parent->left) q.push(parent->left);
                if (parent->right) q.push(parent->right);
            }
        }
        return level;
    }
};
