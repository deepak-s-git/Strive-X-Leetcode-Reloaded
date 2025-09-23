/*
Problem: Minimum Number of Arrows to Burst Balloons (LeetCode #452)
-------------------------------------------------------------------
You are given a list of balloons where each balloon is represented by 
an interval [x_start, x_end]. A balloon can be burst by shooting a single 
arrow at some point `x` if x_start <= x <= x_end.

Return the minimum number of arrows required to burst all balloons.

Examples:
---------
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One arrow at x=6 and another at x=12.

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4

Constraints:
------------
- 1 <= points.length <= 10^5
- points[i].length == 2
- -2^31 <= x_start < x_end <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// Approach: Greedy Interval Overlap
// -----------------------------------------------------------------------------
// Idea:
// - Sort intervals by starting point.
// - Use a "current overlapping interval" tracked by `currentEnd`.
// - If the next balloon starts after `currentEnd`, 
//   we need a new arrow and reset `currentEnd`.
// - Else, shrink the overlap (`currentEnd = min(currentEnd, balloon[i][1])`).
//
// Time Complexity: O(n log n)  (due to sorting)
// Space Complexity: O(1)
//
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& balloons) {
        sort(balloons.begin(), balloons.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int arrowsNeeded = 1;
        int currentEnd = balloons[0][1];

        for (int i = 1; i < balloons.size(); i++) {
            if (balloons[i][0] > currentEnd) {
                arrowsNeeded++;
                currentEnd = balloons[i][1];
            } else {
                currentEnd = min(currentEnd, balloons[i][1]);
            }
        }

        return arrowsNeeded;
    }
};
