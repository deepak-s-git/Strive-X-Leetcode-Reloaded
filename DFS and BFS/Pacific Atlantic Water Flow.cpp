/*
Problem: Pacific Atlantic Water Flow (LeetCode #417)
----------------------------------------------------
You are given an `m x n` matrix of non-negative integers `heights` where
`heights[r][c]` represents the height above sea level at cell `(r, c)`.

The Pacific ocean touches the left and top edges of the matrix, and
the Atlantic ocean touches the right and bottom edges.

Water can flow from a cell to another one with an equal or lower height.

Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

Example:
--------
Input:
heights = [
  [1,2,2,3,5],
  [3,2,3,4,4],
  [2,4,5,3,1],
  [6,7,1,4,5],
  [5,1,1,2,4]
]

Output:
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Explanation:
Water from these coordinates can reach both the Pacific (top/left) and Atlantic (bottom/right) oceans.

Constraints:
------------
- m == heights.length
- n == heights[i].length
- 1 <= m, n <= 200
- 0 <= heights[i][j] <= 10^5
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Reverse DFS from Ocean Borders
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Instead of checking which cells can reach the oceans (which is expensive),
//   we reverse the logic: start DFS from the oceans and mark cells that can
//   flow **into** them.
// - Do two separate traversals:
//   1. From Pacific (top row + left column)
//   2. From Atlantic (bottom row + right column)
// - Any cell visited in both traversals can flow to both oceans.
//
// ⚙️ Steps:
// 1. Create two visited matrices `pac` and `atl` for Pacific and Atlantic reachability.
// 2. Run DFS from all Pacific border cells and all Atlantic border cells.
// 3. Collect all cells where `pac[i][j] && atl[i][j]`.
//
// ⏱️ Time Complexity: O(m * n) – Each cell is visited at most twice.
// 📦 Space Complexity: O(m * n) – For visited arrays and recursion stack.
// -----------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        // 🌊 Pacific Ocean: top row and left column
        for (int i = 0; i < n; i++) {
            dfs(h, pac, i, 0, -1);       // left edge
            dfs(h, atl, i, m - 1, -1);   // right edge (Atlantic)
        }
        for (int j = 0; j < m; j++) {
            dfs(h, pac, 0, j, -1);       // top edge
            dfs(h, atl, n - 1, j, -1);   // bottom edge (Atlantic)
        }

        // ✅ Cells reachable by both oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }

private:
    // 🔁 DFS: mark reachable cells for each ocean
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int x, int y, int prev) {
        int n = h.size(), m = h[0].size();

        // ⛔ Out of bounds / already visited / cannot flow uphill
        if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || h[x][y] < prev) return;

        vis[x][y] = true;  // ✅ Mark as reachable

        // 🌊 Explore in 4 directions
        dfs(h, vis, x + 1, y, h[x][y]);
        dfs(h, vis, x - 1, y, h[x][y]);
        dfs(h, vis, x, y + 1, h[x][y]);
        dfs(h, vis, x, y - 1, h[x][y]);
    }
};
