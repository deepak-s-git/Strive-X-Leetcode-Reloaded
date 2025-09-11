/*
Problem: Convert 1D Array Into 2D Array (LeetCode #2022)
---------------------------------------------------------
You are given a 1D array original, and two integers m and n.
You are tasked with creating a 2D array with m rows and n columns using all the elements from original.

The 2D array should be filled row by row.
If it is not possible to form such a matrix, return an empty 2D array.

Examples:
----------
Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]

Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]

Input: original = [1,2], m = 1, n = 1
Output: []

Constraints:
-------------
- 1 <= original.length <= 5 * 10^4
- 1 <= original[i] <= 10^5
- 1 <= m, n <= 4 * 10^4
*/


// -----------------------------------------------------------------------------
// Approach 1: Manual Index Mapping
// -----------------------------------------------------------------------------
/*
Idea:
- Each element in the 1D array maps to position [i][j] in the 2D array.
- Use formula: ans[i][j] = original[i * n + j].
- If m * n != size of original, return empty matrix.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
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
// Approach 2: Using Vector Ranges
// -----------------------------------------------------------------------------
/*
Idea:
- For each row, take a slice of size n from the original vector.
- Use iterators to create sub-vectors directly.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            ans.push_back(vector<int>(original.begin() + i * n,
                                      original.begin() + (i + 1) * n));
        }
        return ans;
    }
};
