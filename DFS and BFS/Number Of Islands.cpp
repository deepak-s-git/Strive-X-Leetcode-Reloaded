/*
Problem: Number of Islands (LeetCode #200)
------------------------------------------
Given an `m x n` binary grid `grid` where `'1'` represents land and `'0'` represents water,
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are surrounded by water.

Example:
--------
Input:
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

Output: 3

Explanation:
- Island 1: Top-left 2x2 block
- Island 2: Middle single '1'
- Island 3: Bottom-right 2 connected '1's

Constraints:
------------
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: BFS (Iterative)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Traverse the grid. Each time you find a '1', it’s a new island.
// - Use BFS to mark the entire connected component as '0' (visited) to avoid recounting.
//
// ⚙️ Steps:
// 1. Loop through all cells.
// 2. When you find '1', increment island count.
// 3. Use BFS from that cell to mark all connected land as visited.
//
// ⏱️ Time Complexity: O(m * n)
// 📦 Space Complexity: O(min(m, n)) for queue (BFS)
// -----------------------------------------------------------------------------
class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int n = g.size(), m = n ? g[0].size() : 0, cnt = 0;
        vector<int> d = {0, 1, 0, -1, 0}; // direction array (4-directional)

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '1') {
                    cnt++;
                    g[i][j] = '0'; // mark as visited
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    // 🔁 BFS traversal
                    while (!q.empty()) {
                        auto [x, y] = q.front(); 
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + d[k], ny = y + d[k + 1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == '1') {
                                g[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: DFS (Recursive)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Similar to BFS, but use recursion (DFS) instead of a queue.
// - Each time you see a '1', run DFS to mark the entire island.
//
// ⚙️ Steps:
// 1. Traverse grid.
// 2. On finding '1', increment count and DFS mark the island as visited.
//
// ⏱️ Time Complexity: O(m * n)
// 📦 Space Complexity: O(m * n) due to recursion stack
// -----------------------------------------------------------------------------
class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int n = g.size(), m = n ? g[0].size() : 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '1') {
                    cnt++;
                    dfs(g, i, j); // mark entire island
                }
            }
        }
        return cnt;
    }

private:
    // 🔁 DFS to mark island
    void dfs(vector<vector<char>>& g, int x, int y) {
        int n = g.size(), m = g[0].size();
        if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '0') return;

        g[x][y] = '0'; // mark visited
        dfs(g, x + 1, y);
        dfs(g, x - 1, y);
        dfs(g, x, y + 1);
        dfs(g, x, y - 1);
    }
};
