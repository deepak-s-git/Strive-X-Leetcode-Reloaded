/*
Problem: Path Sum III (LeetCode #437)
-------------------------------------
Given a binary tree and an integer target, return the number of paths
where the sum of the values along the path equals `target`.

- The path does **not** need to start or end at the root or a leaf,
  but it must go downwards (parent → child).

Example:
--------
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], target = 8
Output: 3
Explanation:
The paths that sum to 8 are:
1. 5 → 3
2. 5 → 2 → 1
3. -3 → 11

Constraints:
------------
- The number of nodes in the tree is in the range [0, 1000].
- -10^9 <= Node.val <= 10^9
- -1000 <= target <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: DFS + Backtracking (Prefix-style path checking)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Traverse the tree using DFS, keeping track of the current path from root.
// - For each node, iterate backwards through the path to check if any subpath
//   sums to the target.
// - Increment counter if a matching sum is found.
// - Backtrack after exploring left and right children.
//
// ⏱️ Time Complexity: O(N^2) worst-case (for each node, we traverse its path)
// 📦 Space Complexity: O(H + H) recursion stack + current path, H = tree height
// -----------------------------------------------------------------------------
class Solution {
public:
    int cnt = 0;

    int pathSum(TreeNode* root, int target) {
        vector<int> cur;
        dfs(root, (long long)target, cur);
        return cnt;
    }

private:
    void dfs(TreeNode* node, long long target, vector<int>& cur) {
        if (!node) return;

        cur.push_back(node->val);

        // 🔁 Check all subpaths ending at current node
        long long s = 0;
        for (int i = cur.size() - 1; i >= 0; i--) {
            s += cur[i];
            if (s == target) cnt++;
        }

        dfs(node->left, target, cur);
        dfs(node->right, target, cur);

        cur.pop_back(); // 🔙 Backtrack
    }
};
