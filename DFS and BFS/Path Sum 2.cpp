/*
Problem: Path Sum II (LeetCode #113)
------------------------------------
Given a binary tree and a target sum, return all root-to-leaf paths
where the sum of the node values in the path equals `target`.

Example:
--------
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], target = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths where the sum of nodes equals 22.

Constraints:
------------
- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= target <= 1000000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: DFS with Backtracking
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Perform DFS from root to leaf, keeping track of current path and remaining sum.
// - When a leaf is reached, check if the remaining sum equals the leaf value.
// - If yes, add the current path to the result.
// - Backtrack to explore other paths.
//
// ⏱️ Time Complexity: O(N) where N is the number of nodes (each node visited once)
// 📦 Space Complexity: O(H) recursion stack + O(H) path storage, H = tree height
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node, vector<int>& currentPath, int remaining) {
        if (!node) return;

        currentPath.push_back(node->val);

        // ✅ Check leaf and sum
        if (!node->left && !node->right && remaining == node->val)
            result.push_back(currentPath);

        // 🔁 Recurse left and right
        dfs(node->left, currentPath, remaining - node->val);
        dfs(node->right, currentPath, remaining - node->val);

        currentPath.pop_back(); // 🔙 Backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> currentPath;
        dfs(root, currentPath, target);
        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Alternative DFS Style with sum accumulator
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> curPath;
        dfs(root, target, 0, curPath, ans);
        return ans;
    }

    void dfs(TreeNode* node, int target, int sum,
             vector<int>& path, vector<vector<int>>& ans) {
        if (!node) return;

        sum += node->val;
        path.push_back(node->val);

        if (!node->left && !node->right && sum == target) {
            ans.push_back(path);
        }

        dfs(node->left, target, sum, path, ans);
        dfs(node->right, target, sum, path, ans);

        path.pop_back(); // 🔙 Backtrack
    }
};
