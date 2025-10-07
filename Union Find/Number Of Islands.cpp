/*
🔎 Problem: Number of Islands (LeetCode 200)

Given an m x n 2D binary grid `grid` which represents a map of '1's (land) and '0's (water),
return the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are surrounded by water.

📥 Example:
Input:
grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]

Output: 3

Explanation:
- There is one island in the top-left,
- One island in the middle,
- And one island in the bottom-right.

⚙️ Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'
*/


/* ================================================================
   ✅ Approach 1: Union-Find (Disjoint Set Union - DSU)
   ================================================================
   🔍 Intuition:
   - Treat each cell as a node in a graph.
   - Initially, each land cell is its own island.
   - For every adjacent pair of land cells, union them together.
   - Every successful union means two islands merged into one.
   - Finally, the number of islands is the number of unique parents (components).

   🧠 Steps:
   1. Iterate through the grid and for each '1', count it as a new island.
   2. For each '1', check its four neighbors. If the neighbor is also '1', union them.
   3. Every successful union reduces the island count by 1.
   4. Return the final count.

   ⏱️ Complexity:
   - Time: O(M * N * α(M*N)), where α is the inverse Ackermann function (almost constant)
   - Space: O(M * N) for the Union-Find structure
================================================================ */

class UF {
    vector<int> parent, rank;
public:
    // Constructor: initializes parent and rank arrays
    UF(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    // Find with path compression
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    // Union by rank
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] > rank[b]) swap(a, b);
        parent[a] = b;
        if (rank[a] == rank[b]) rank[b]++;
    }

    // Check if two nodes are in the same set
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    int n, m;

    // Check if cell (i, j) is within grid bounds
    bool inBounds(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    // Convert 2D coordinates to 1D index
    int cellId(int i, int j) {
        return i * m + j;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int totalCells = n * m;
        int islands = 0;

        UF dsu(totalCells);
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Traverse all cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '1') continue;

                // Mark visited to avoid double counting
                grid[i][j] = '2';
                islands++;
                int id1 = cellId(i, j);

                // Check 4 neighbors
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (!inBounds(ni, nj) || grid[ni][nj] != '1') continue;

                    int id2 = cellId(ni, nj);

                    // If they are not already connected, union them
                    if (!dsu.connected(id1, id2)) {
                        dsu.unite(id1, id2);
                        islands--;
                    }
                }
            }
        }

        return islands;
    }
};
