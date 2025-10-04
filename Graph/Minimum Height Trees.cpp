/*
Problem: Minimum Height Trees (LeetCode #310)
--------------------------------------------
We are given an undirected tree with `n` nodes labeled `0` to `n-1`.
We want to find all the **roots of Minimum Height Trees (MHTs)** — these are the nodes
from which, if we root the tree, the height is minimized.

Example:
--------
Input:
n = 4
edges = [[1,0],[1,2],[1,3]]

Output:
[1]

Explanation:
- Tree rooted at node 1 → height = 1 (minimum possible)
- Trees rooted at 0, 2, or 3 → height = 2

Constraints:
------------
- 1 <= n <= 2 * 10^4
- edges.length == n - 1
- 0 <= edges[i][0], edges[i][1] < n
- All edges are unique and form a valid tree.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Trim Leaves Layer-by-Layer (Topological BFS)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// In a tree, the **centroid(s)** are the node(s) that minimize tree height.
// These centroids are at the "center" — all other nodes form layers outward.
//
// If we repeatedly remove leaf nodes (nodes with degree = 1), the remaining nodes
// will eventually be the centroid(s). A tree has either 1 or 2 centroids.
//
// 🧠 Algorithm:
// 1. Build the adjacency list and compute degrees for all nodes.
// 2. Add all leaf nodes (degree = 1) to a queue.
// 3. Iteratively remove leaves layer by layer, updating neighbor degrees.
// 4. Stop when ≤ 2 nodes remain — these are our MHT roots.
//
// ⏱️ Time Complexity: O(n)  — Each edge and node processed once.
// 📦 Space Complexity: O(n)  — Graph storage + queue.
// -----------------------------------------------------------------------------

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 🟡 Special case: Only one node → it's the centroid
        if (n == 1) return {0};

        // Step 1: Build adjacency list and degree array
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: Initialize first layer of leaves (degree == 1)
        queue<int> leafQueue;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) leafQueue.push(i);
        }

        // Step 3: Trim leaves level by level until ≤ 2 nodes remain
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leafCount = leafQueue.size();
            remainingNodes -= leafCount;  // remove all current leaves

            // Remove current leaves and update neighbors
            for (int i = 0; i < leafCount; i++) {
                int leaf = leafQueue.front();
                leafQueue.pop();

                for (int neighbor : graph[leaf]) {
                    if (--degree[neighbor] == 1) {
                        // becomes a new leaf in the next round
                        leafQueue.push(neighbor);
                    }
                }
            }
        }

        // Step 4: Remaining nodes in queue are the centroids
        vector<int> result;
        while (!leafQueue.empty()) {
            result.push_back(leafQueue.front());
            leafQueue.pop();
        }

        return result;
    }
};
