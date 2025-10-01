/*
Problem: Maximum Depth of Binary Tree (LeetCode #104)
-----------------------------------------------------
Given the `root` of a binary tree, return its **maximum depth**.

- The maximum depth is the number of nodes along the longest path 
  from the root node down to the farthest leaf node.

Example:
--------
Input: root = [3,9,20,null,null,15,7]  
Output: 3  
Explanation: The longest path is 3 → 20 → 15 or 3 → 20 → 7

Constraints:
------------
- The number of nodes is in the range [0, 10⁴]
- -100 <= Node.val <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Recursive DFS (Top-Down)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - The depth of a tree = 1 (root) + max(depth of left, depth of right).
// - Recursively calculate depth of subtrees until leaf nodes.
//
// ⏱️ Time Complexity: O(N) – each node is visited once
// 📦 Space Complexity: O(H) – recursion depth (H = height of tree)
// -----------------------------------------------------------------------------
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // ✅ Base case: empty tree

        // 🌲 Recurse on left and right subtrees and return max depth
        return 1 + max(maxDepth(root->left), maxDepth(root->right));        
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: BFS (Level Order Traversal)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Use a queue to traverse the tree level by level.
// - Increment depth count at each level until traversal ends.
// - Final depth = total number of levels traversed.
//
// ⚙️ Steps:
// 1. Push root into queue.
// 2. For each level, process all nodes and push their children.
// 3. Increase depth counter after each level.
//
// ⏱️ Time Complexity: O(N) – each node is visited once
// 📦 Space Complexity: O(W) – width of the tree (worst-case: O(N))
// -----------------------------------------------------------------------------
#include <queue>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* rootNode) {
        if (!rootNode) return 0; // ✅ Edge case: empty tree

        queue<TreeNode*> levelQueue;
        levelQueue.push(rootNode);
        int depthCount = 0;

        // 🔁 Level-order traversal (BFS)
        while (!levelQueue.empty()) {
            depthCount++;                        // ✅ New level found
            int nodesInLevel = levelQueue.size(); // Number of nodes at current level

            // Process all nodes in this level
            for (int i = 0; i < nodesInLevel; i++) {
                TreeNode* currentNode = levelQueue.front();
                levelQueue.pop();

                if (currentNode->left) levelQueue.push(currentNode->left);
                if (currentNode->right) levelQueue.push(currentNode->right);
            }
        }
        return depthCount; // ✅ Total number of levels = max depth
    }
};
