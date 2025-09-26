/*
Problem: Non-overlapping Intervals (LeetCode #435)
--------------------------------------------------
Given an array of intervals `intervals` where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example:
--------
Input:  intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1

Explanation:
- Remove [1,3] to make the rest non-overlapping: [[1,2],[2,3],[3,4]]

Constraints:
------------
- 1 <= intervals.length <= 10^5
- intervals[i].length == 2
- -5 * 10^4 <= starti < endi <= 5 * 10^4
*/


// ✅ Approach: Greedy by End Time
// ------------------------------
// Intuition:
// - If we always keep the interval with the smallest `end` when overlapping occurs,
//   we maximize the remaining space for future intervals (like Activity Selection).
//
// Steps:
// 1. Sort all intervals by their `end` time (earliest ending first).
// 2. Iterate through the list and check if the current interval overlaps with the previous one kept.
// 3. If it overlaps, increment the `overLaps` counter (we remove one).
// 4. If it does not overlap, update `lastEnd` to the current interval's end.
//
// Why this works:
// - This greedy approach ensures we always keep intervals that leave the most room for future ones.
// - Equivalent to selecting the maximum number of non-overlapping intervals and subtracting from total.
//
// Time Complexity: O(n log n) → for sorting
// Space Complexity: O(1)      → no extra space used
//
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 🔹 Sort by end time (earliest finishing first)
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int overLaps = 0;                  // count of intervals to remove
        int lastEnd = intervals[0][1];     // track the end of the last non-overlapping interval

        // 🔁 Iterate and count overlaps
        for(int i = 1; i < intervals.size(); i++) {
            // ✅ If overlap: current interval starts before previous one ends
            if(intervals[i][0] < lastEnd) {
                overLaps++; // remove one (prefer removing the one with larger end time)
            } 
            // ❌ No overlap: update lastEnd
            else {
                lastEnd = intervals[i][1];
            }
        }

        return overLaps;  // total intervals we removed
    }
};
