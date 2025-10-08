/*
🚶‍♂️ Problem: Unique Paths (LeetCode 62)

You are given a grid with `rows` rows and `cols` columns.  
You start at the **top-left corner (0,0)** and your goal is to reach the **bottom-right corner (rows-1, cols-1)**.  
At any point, you can only move **right** or **down**.

Return the **total number of unique paths** to reach the destination.

📥 Example 1:
Input: rows = 3, cols = 7
Output: 28

📥 Example 2:
Input: rows = 3, cols = 2
Output: 3
Explanation:
→→↓  
↓→→  
↓→→  

⚙️ Constraints:
- 1 <= rows, cols <= 100
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (1D Space Optimized)
   ================================================================
   🔍 Intuition:
   - Classic grid DP problem: `dp[r][c]` = number of unique paths to cell (r,c).
   - Since `dp[r][c]` = `dp[r-1][c] + dp[r][c-1]`, we only need the previous row.
   - Optimize space using a 1D array: `paths[c]` stores ways to reach column `c`.

   🧠 Transition Formula:
   paths[c] = paths[c] + paths[c-1]
   - `paths[c]` → ways from above
   - `paths[c-1]` → ways from left

   📊 Dry Run:
   rows = 3, cols = 3

   Initial: paths = [1, 1, 1]
   Row 1:   paths = [1, 2, 3]
   Row 2:   paths = [1, 3, 6] ✅

   ⏱️ Complexity:
   - Time:  O(rows * cols)
   - Space: O(cols)   (optimized from O(rows * cols))
================================================================ */

class Solution {
public:
    int uniquePaths(int rows, int cols) {
        std::vector<int> paths(cols, 1); // Base case: first row has only 1 way to move (all rights)

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                paths[c] += paths[c - 1]; // ways from top + ways from left
            }
        }

        return paths[cols - 1]; // bottom-right cell
    }
};
