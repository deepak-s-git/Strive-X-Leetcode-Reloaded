/*
Problem: Path Sum (LeetCode #112)
---------------------------------
Given the root of a binary tree and an integer `targetSum`, return `true` 
if the tree has a **root-to-leaf** path such that adding up all the values 
along the path equals `targetSum`.

- A leaf is a node with no children.

Example:
--------
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22  
Output: true  
Explanation: 5 → 4 → 11 → 2 sums to 22.

Constraints:
------------
- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= targetSum <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Recursive DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Traverse the tree from root to leaf, reducing `targetSum` by the current node's value.
// - When we reach a leaf node, check if the remaining sum equals the leaf's value.
// - If any root-to-leaf path satisfies the sum → return true.
//
// ⚙️ Steps:
// 1. If root is NULL → no path exists.
// 2. Subtract current node’s value from `remainingSum`.
// 3. If it’s a leaf node → check if remaining sum is 0.
// 4. Otherwise, recursively explore left and right subtrees.
//
// ⏱️ Time Complexity: O(N) – visits each node once.
// 📦 Space Complexity: O(H) – recursion depth (H = height of tree).
// -----------------------------------------------------------------------------

class Solution {
public:
    bool hasPathSum(TreeNode* rootNode, int remainingSum) {
        // ✅ Base case: empty tree → no path
        if (!rootNode) return false;

        // 📉 Subtract current node’s value from remaining sum
        remainingSum -= rootNode->val;

        // ✅ If leaf node → check if remainingSum is 0
        if (!rootNode->left && !rootNode->right) {
            return remainingSum == 0;
        }

        // 🔁 Recurse on left and right subtrees
        return hasPathSum(rootNode->left, remainingSum) || 
               hasPathSum(rootNode->right, remainingSum);
    }
};
