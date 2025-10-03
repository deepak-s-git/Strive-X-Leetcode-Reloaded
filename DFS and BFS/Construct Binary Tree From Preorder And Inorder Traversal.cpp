/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal (LeetCode #105)
----------------------------------------------------------------------------------
Given two integer arrays `preorder` and `inorder`, where `preorder` is the preorder
traversal of a binary tree and `inorder` is the inorder traversal of the same tree,
construct and return the binary tree.

Example:
--------
Input:
preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]

Output:
    3
   / \
  9  20
    /  \
   15   7

Constraints:
------------
- 1 <= preorder.length <= 3000
- inorder.length == preorder.length
- -3000 <= Node.val <= 3000
- All the values are unique.
- `preorder` and `inorder` represent a valid binary tree.
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Recursive Construction using Preorder + Inorder Index Map
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Preorder: [Root | Left Subtree | Right Subtree]
// - Inorder:  [Left Subtree | Root | Right Subtree]
// - Pick the current root from preorder (start to end).
// - Find its position in inorder (split into left and right subtrees).
// - Recursively build left and right subtrees.
//
// ⏱️ Time Complexity: O(N) — each node processed once, lookup O(1) with hash map
// 📦 Space Complexity: O(N) — recursion + hash map
// -----------------------------------------------------------------------------
class Solution {
private:
    int preorderIndex;
    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;

        int val = preorder[preorderIndex++];      // current root
        TreeNode* root = new TreeNode(val);

        int mid = inorderIndex[val];              // find root in inorder
        root->left = build(preorder, l, mid - 1); // build left subtree
        root->right = build(preorder, mid + 1, r);// build right subtree

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderIndex.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;        // store value -> index
        }
        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Iterative Construction using Stack (O(N))
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Use preorder to create nodes (root first).
// - Use a stack to track the path.
// - If stack top != inorder element → create left child.
// - Else → pop until stack top != inorder, then create right child.
//
// ⏱️ Time Complexity: O(N)
// 📦 Space Complexity: O(N) — stack space
// -----------------------------------------------------------------------------
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        int inorderIndex = 0;

        for (int i = 1; i < preorder.size(); i++) {
            int val = preorder[i];
            TreeNode* node = st.top();

            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(val);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[inorderIndex]) {
                    node = st.top();
                    st.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(val);
                st.push(node->right);
            }
        }

        return root;
    }
};
