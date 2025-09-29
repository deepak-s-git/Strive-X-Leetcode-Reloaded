/*
Problem: Subsets II (LeetCode #90)
----------------------------------
Given an integer array `nums` that may contain duplicates, return all possible 
subsets (the power set). The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example:
--------
Input:  nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Constraints:
------------
- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking with Duplicate Skipping
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// This is similar to the basic subsets problem, but we need to handle duplicates.
// We first sort the array so that duplicates are adjacent. Then, when we **exclude**
// a number, we skip all its duplicates to avoid generating the same subset multiple times.
//
// ⚡ Why This Works:
// By always skipping consecutive duplicates when *not choosing* an element, 
// we guarantee that each unique subset is generated only once.
//
// ⏱️ Time Complexity: O(2^n * n)
//      - 2^n possible subsets, each taking O(n) time to copy
// 📦 Space Complexity: O(n) recursion stack + O(2^n) result storage
// -----------------------------------------------------------------------------


class Solution {
public:
    // 🔁 Recursive helper to generate all unique subsets
    void getAllSubsets(vector<int>& nums, vector<int>& current, int i,
                       vector<vector<int>>& allSubsets) {
        // ✅ Base case: if we've processed all elements → add current subset
        if (i == nums.size()) {
            allSubsets.push_back(current);
            return;
        }

        // 🔁 Choice 1: Include nums[i]
        current.push_back(nums[i]);
        getAllSubsets(nums, current, i + 1, allSubsets);

        // 🔙 Backtrack: remove last element
        current.pop_back();

        // 🔁 Choice 2: Exclude nums[i] → but skip all its duplicates
        int nextIndex = i + 1;
        while (nextIndex < nums.size() && nums[nextIndex] == nums[nextIndex - 1]) {
            nextIndex++; // ✅ Skip duplicates
        }
        getAllSubsets(nums, current, nextIndex, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 📌 Sort so duplicates are adjacent
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> current;
        getAllSubsets(nums, current, 0, allSubsets);
        return allSubsets;
    }
};
