/*
Problem: All Nodes Distance K in Binary Tree (LeetCode #863)
-------------------------------------------------------------
Given the root of a binary tree, a target node, and an integer K, return 
the values of all nodes that are exactly K distance from the target node.

Example:
--------
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
Explanation: Nodes 7, 4, and 1 are at distance 2 from target node 5.

Constraints:
------------
- The number of nodes in the tree is in the range [1, 500].
- 0 <= Node.val <= 500
- All the values Node.val are unique.
- target is the value of one of the nodes in the tree.
- 0 <= K <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: BFS + Parent Mapping
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Traverse tree to store parent pointers for each node.
// - Then perform BFS starting from the target node.
// - At each BFS level, we explore left, right, and parent nodes.
// - Stop when BFS reaches distance K.
//
// ⏱️ Time Complexity: O(N) – each node visited once
// 📦 Space Complexity: O(N) – for parent map and BFS queue
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<int, TreeNode*> parentMap; 
        queue<TreeNode*> q;
        q.push(root);

        // 🔁 Build parent pointers
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                parentMap[node->left->val] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right->val] = node;
                q.push(node->right);
            }
        }

        // 🔁 BFS from target
        unordered_map<int, bool> visited;
        q.push(target);
        visited[target->val] = true;

        while (k-- && !q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left->val]) {
                    visited[curr->left->val] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right->val]) {
                    visited[curr->right->val] = true;
                    q.push(curr->right);
                }
                if (parentMap.count(curr->val) && !visited[parentMap[curr->val]->val]) {
                    visited[parentMap[curr->val]->val] = true;
                    q.push(parentMap[curr->val]);
                }
            }
        }

        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: DFS + Subtree Nodes
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Use DFS to find target node and distance from each node to target.
// - When distance matches K, add the node to result.
// - Recursively add nodes in subtrees at proper distance.
//
// ⏱️ Time Complexity: O(N)
// 📦 Space Complexity: O(H) recursion stack (H = tree height)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> result;

    void addSubtreeNodes(TreeNode* node, int dist, int K) {
        if (!node) return;
        if (dist == K) {
            result.push_back(node->val);
            return;
        }
        addSubtreeNodes(node->left, dist + 1, K);
        addSubtreeNodes(node->right, dist + 1, K);
    }

    int dfs(TreeNode* node, TreeNode* target, int K) {
        if (!node) return -1;

        if (node == target) {
            addSubtreeNodes(node, 0, K);
            return 0;
        }

        int leftDist = dfs(node->left, target, K);
        if (leftDist != -1) {
            if (leftDist + 1 == K) result.push_back(node->val);
            else addSubtreeNodes(node->right, leftDist + 2, K);
            return leftDist + 1;
        }

        int rightDist = dfs(node->right, target, K);
        if (rightDist != -1) {
            if (rightDist + 1 == K) result.push_back(node->val);
            else addSubtreeNodes(node->left, rightDist + 2, K);
            return rightDist + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, target, K);
        return result;
    }
};
