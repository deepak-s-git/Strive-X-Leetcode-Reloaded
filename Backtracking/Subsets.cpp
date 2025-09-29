/*
Problem: Subsets (LeetCode #78)
-------------------------------
Given an integer array `nums` of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

Example:
--------
Input:  nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Constraints:
------------
- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
- All elements of nums are unique.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking (DFS)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// The idea is to explore two choices for every element:
//   1. Include the current element in the subset.
//   2. Exclude the current element and move forward.
//
// By exploring both choices recursively, we generate all possible subsets.
//
// ⚡ Why This Works:
// Each element has 2 choices → total 2^n subsets. Backtracking explores them efficiently.
//
// ⏱️ Time Complexity: O(2^n * n)
//      - 2^n subsets, and copying each subset takes O(n)
// 📦 Space Complexity: O(n) recursion depth + O(2^n) result storage
// -----------------------------------------------------------------------------
#include <vector>
using namespace std;

class Solution {
public:
    // 🔁 Recursive helper to generate all subsets
    void getAllSubsets(vector<int>& nums, vector<int>& current, int i,
                       vector<vector<int>>& allSubsets) {
        // ✅ Base case: reached the end → store the current subset
        if (i == nums.size()) {
            allSubsets.push_back(current);
            return;
        }

        // 🔁 Choice 1: Include nums[i]
        current.push_back(nums[i]);
        getAllSubsets(nums, current, i + 1, allSubsets);

        // 🔙 Backtrack: remove last element
        current.pop_back();

        // 🔁 Choice 2: Exclude nums[i]
        getAllSubsets(nums, current, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> current;
        getAllSubsets(nums, current, 0, allSubsets); // start recursion from index 0
        return allSubsets;
    }
};
