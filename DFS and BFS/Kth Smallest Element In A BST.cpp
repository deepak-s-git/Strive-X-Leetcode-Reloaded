// 🏷️ LeetCode 230 - Kth Smallest Element in a BST
// ---------------------------------------------------------------
// ✅ Approach 1: Preorder Traversal + Sort
// ✅ Approach 2: Inorder Traversal (Sorted Order Property of BST)
// ✅ Approach 3: Optimized Inorder DFS (O(k) early stop)
// ---------------------------------------------------------------
// 🌲 TreeNode structure is assumed to be defined as:
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };


// --------------------------------------------------------------------
// ✅ Approach 1: Preorder Traversal + Sort
// --------------------------------------------------------------------
// ⏱️ Time: O(N log N) → N for traversal + sort
// 📦 Space: O(N) → storing all nodes
// 📌 Explanation: Traverse the tree (any order), collect all values, sort them, return kth-1 index.
class Solution_PreorderSort {
public:
    void preOrder(TreeNode* node, vector<int> &vals) {
        if (!node) return;
        vals.push_back(node->val);              // Visit root
        preOrder(node->left, vals);             // Visit left
        preOrder(node->right, vals);            // Visit right
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        preOrder(root, vals);
        sort(vals.begin(), vals.end());         // Sorting to get kth smallest
        return vals[k - 1];
    }
};


// --------------------------------------------------------------------
// ✅ Approach 2: Inorder Traversal (BST Property)
// --------------------------------------------------------------------
// ⏱️ Time: O(N) → single inorder traversal
// 📦 Space: O(N) → storing inorder order
// 📌 Explanation: Inorder traversal of BST gives a sorted list → directly access kth element.
class Solution_Inorder {
public:
    void inOrder(TreeNode* node, vector<int> &order) {
        if (!node) return;
        inOrder(node->left, order);            // Left subtree
        order.push_back(node->val);            // Visit root
        inOrder(node->right, order);           // Right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        inOrder(root, order);
        return order[k - 1];
    }
};


// --------------------------------------------------------------------
// ✅ Approach 3: Optimized Inorder DFS (No Extra Space, O(k) Time)
// --------------------------------------------------------------------
// ⏱️ Time: O(k) average → stops traversal once kth element is found
// 📦 Space: O(H) → recursion stack (H = height of tree)
// 📌 Explanation: Perform inorder traversal but stop once kth node is reached.
class Solution_OptimizedDFS {
public:
    void dfs(TreeNode* node, int &count, int &result, int k) {
        if (!node) return;

        dfs(node->left, count, result, k);    // Visit left first

        count++;                              // Increment node counter
        if (count == k) {                     // Found kth node
            result = node->val;
            return;
        }

        dfs(node->right, count, result, k);   // Visit right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        dfs(root, count, result, k);
        return result;
    }
};
