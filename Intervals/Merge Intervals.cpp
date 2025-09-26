/*
Problem: Merge Intervals (LeetCode #56)
----------------------------------------
Given an array of `intervals` where intervals[i] = [start, end], merge all overlapping intervals 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Examples:
---------
Input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Input:  intervals = [[1,4],[4,5]]
Output: [[1,5]]

Constraints:
------------
- 1 <= intervals.length <= 10^4
- intervals[i].length == 2
- 0 <= start <= end <= 10^4
*/


// ✅ Approach: Sort + Merge in One Pass
// -------------------------------------
// 1. Sort all intervals by their starting time.
// 2. Iterate through them and:
//    - If the current interval does not overlap with the previous merged interval → push it into result.
//    - If it overlaps → merge by updating the end time.
//
// Why it works:
// - Sorting ensures that overlapping intervals are adjacent.
// - One linear pass is enough to merge them.
//
// Time Complexity: O(n log n) → due to sorting.
// Space Complexity: O(n)      → for storing merged intervals.
//
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 🔹 Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        // 🔹 Step 2: Merge intervals
        for (int i = 0; i < intervals.size(); i++) {
            // If result is empty OR no overlap → push new interval
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } 
            // Else → merge by updating the end time
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};
