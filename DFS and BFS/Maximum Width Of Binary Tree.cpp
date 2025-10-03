/*
Problem: Maximum Width of Binary Tree (LeetCode #662)
----------------------------------------------------
Given the `root` of a binary tree, return the **maximum width** of the tree.

👉 The width of a level is defined as the length between the end-nodes 
   (the leftmost and rightmost non-null nodes) of that level, 
   including any `null` nodes between them in the complete binary tree representation.

Example:
--------
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation:
Level 0: [1]                       → width = 1
Level 1: [3,2]                    → width = 2
Level 2: [5,3,null,9]            → width = 4 ✅ (maximum)
 
Constraints:
------------
- The number of nodes in the tree is in the range [1, 3000].
- -100 <= Node.val <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: BFS (Level Order Traversal with Position Index)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Perform a level order traversal using a queue.
// - For each node, store its "index" as if it were in a complete binary tree:
//     - root index = 1
//     - left child index = 2 * idx
//     - right child index = 2 * idx + 1
// - At each level: width = (index of last node) - (index of first node) + 1
//
// ⏱️ Time Complexity: O(N)  — visit every node once
// 📦 Space Complexity: O(N) — queue space for BFS
// -----------------------------------------------------------------------------
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int mx = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1LL});
        
        while (!q.empty()) {
            int sz = q.size();
            long long start = q.front().second;     // leftmost index at this level
            long long end   = q.back().second;      // rightmost index at this level
            mx = max(mx, (int)(end - start + 1));   // width calculation
            
            for (int i = 0; i < sz; i++) {
                auto [node, pos] = q.front();
                q.pop();
                
                long long idx = pos - start;  // normalize to avoid overflow
                if (node->left)  q.push({node->left,  2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }
        }
        return mx;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: DFS (Preorder with Leftmost Position Tracking)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Use DFS and record the "first index" seen at each depth (leftmost node).
// - At each node: width = current index - first index at this depth + 1
// - Recursively compute maximum width.
//
// ⏱️ Time Complexity: O(N)  
// 📦 Space Complexity: O(H) (recursion depth ~ tree height)
// -----------------------------------------------------------------------------
class Solution {
public:
    int mx = 0;

    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;  // leftmost index at each depth
        dfs(root, 1LL, 0, lefts);
        return mx;
    }
    
private:
    void dfs(TreeNode* node, long long pos, int d, vector<int>& lefts) {
        if (!node) return;
        
        if (d >= lefts.size()) lefts.push_back(pos);  // record leftmost index
        
        mx = max(mx, (int)(pos - lefts[d] + 1));      // update width
        
        dfs(node->left,  2 * (pos - lefts[d]), d + 1, lefts);
        dfs(node->right, 2 * (pos - lefts[d]) + 1, d + 1, lefts);
    }
};
