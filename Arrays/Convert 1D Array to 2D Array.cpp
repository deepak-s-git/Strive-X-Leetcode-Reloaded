/*
Problem: Convert 1D Array Into 2D Array (LeetCode #2022)
---------------------------------------------------------
You are given a 0-indexed 1D integer array `original`,
and two integers `m` and `n`.

You must create a 2D array of dimensions m x n using
all elements of `original`.

The elements should be filled row-wise.

If it is impossible (m * n != original.size()),
return an empty 2D array.

Example:
--------
Input:  original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]

Input:  original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]

Input:  original = [1,2], m = 1, n = 1
Output: []

Constraints:
------------
- 1 <= original.length <= 5 * 10^4
- 1 <= m, n <= 4 * 10^4
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Direct Index Mapping
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - If total elements mismatch → return {}
// - Create m x n matrix
// - Map original[i] → ans[row][col]
//   where index = i*n + j
//
// ⏱ Time Complexity: O(m * n)
// 📦 Space Complexity: O(m * n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if ((m * n) != original.size()) {
            return {};
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[i * n + j];
            }
        }

        return ans;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Using Vector Range Constructor
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Instead of manually assigning,
//   directly slice the original array row by row
// - Use vector constructor with iterators
//
// ⏱ Time Complexity: O(m * n)
// 📦 Space Complexity: O(m * n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if ((m * n) != original.size()) {
            return {};
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            ans.push_back(
                vector<int>(
                    original.begin() + i * n,
                    original.begin() + (i + 1) * n
                )
            );
        }

        return ans;
    }
};