/*
Problem: Binary Tree Right Side View (LeetCode #199)
----------------------------------------------------
Given the `root` of a binary tree, imagine yourself standing on the **right side** 
of it. Return the values of the nodes you can see **ordered from top to bottom**.

Example:
--------
Input:
    1
   / \
  2   3
   \   \
    5   4

Output: [1, 3, 4]

Explanation:
- From the right side, we see: 1 (root), 3 (right of level 2), 4 (right of level 3).

Constraints:
------------
- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Level-Order Traversal (BFS)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Perform a standard level-order traversal (BFS) using a queue.
// - At each level, the **last node** processed is the rightmost node visible 
//   from the right side — add it to the result.
//
// ⚙️ Steps:
// 1. Use a queue to traverse the tree level by level.
// 2. Keep track of the last node at each level.
// 3. Push the last node's value into the result vector.
//
// ⏱️ Time Complexity: O(N) – visit each node once.
// 📦 Space Complexity: O(N) – for the queue and output vector.
// -----------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;             // ✅ stores final right side nodes
        queue<TreeNode*> q;                // 🧪 queue for BFS

        if (root) q.push(root);            // 🌱 start BFS if root exists

        while (!q.empty()) {
            int levelSize = q.size();      // 📏 number of nodes in current level
            TreeNode* lastNode = nullptr;  // 🪟 track the last (rightmost) node

            // 🔁 Process all nodes in current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                lastNode = current;        // 💡 always update lastNode

                // 📥 Push children into the queue
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            // ✅ Add the rightmost node of this level to the view
            if (lastNode) rightView.push_back(lastNode->val);
        }

        return rightView;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: DFS (Right-First Traversal) – Optional
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Traverse the tree **right subtree first** so the first node visited at each 
//   depth is the rightmost node.
// - Keep track of the current depth and add the node if it's the first time we 
//   visit that depth.
//
// ⏱️ Time Complexity: O(N)
// 📦 Space Complexity: O(H) – recursion stack (H = tree height)
// -----------------------------------------------------------------------------

class Solution_DFS {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int> &result) {
        if (!node) return;

        // 📌 If visiting this depth for the first time, it's the rightmost node
        if (depth == result.size()) result.push_back(node->val);

        // 🚀 Prioritize right subtree
        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
    }
};
