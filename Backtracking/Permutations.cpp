/*
Problem: Permutations (LeetCode #46)
-------------------------------------
Given an array `arr` of distinct integers, return all possible permutations.

Example:
--------
Input: arr = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
------------
- 1 <= arr.length <= 6
- -10 <= arr[i] <= 10
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking + Swapping
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - We generate permutations by fixing each element at index `idx` and recursively
//   permuting the remaining elements.
// - Swap `arr[idx]` with `arr[j]` to choose the element for current position.
// - Backtrack by swapping back to restore original state.
//
// ⚡ Why This Works:
// Each position can hold any remaining number, and swapping ensures all possible
// arrangements are generated.
//
// ⏱️ Time Complexity: O(n! * n)
//      - n! permutations, each takes O(n) time to copy into result
// 📦 Space Complexity: O(n) recursion stack + O(n! * n) for result storage
// -----------------------------------------------------------------------------


class Solution {
public:
    // 🔁 Recursive helper to generate all permutations starting at idx
    void generate(int idx, vector<vector<int>>& res, vector<int>& arr) {
        // ✅ Base case: if idx reached end → add current permutation
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }

        // 🔁 Try each element for position idx
        for (int j = idx; j < arr.size(); j++) {
            swap(arr[idx], arr[j]);         // choose element arr[j] for current position
            generate(idx + 1, res, arr);   // recurse for next position
            swap(arr[idx], arr[j]);         // backtrack: restore original order
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> res;
        generate(0, res, arr);
        return res;
    }
};
