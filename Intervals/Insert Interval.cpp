/*
Problem: Insert Interval (LeetCode #57)
---------------------------------------
You are given a set of non-overlapping intervals sorted by their start time and a new interval.  
Insert the new interval into the list (merge if necessary) and return the resulting list of intervals.

Example:
--------
Input:  intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Constraints:
------------
- 0 <= intervals.length <= 10^4
- intervals[i].length == 2
- 0 <= starti <= endi <= 10^5
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Merge During Insertion (O(n))
// -----------------------------------------------------------------------------
// Idea:
// - Insert intervals in three steps:
//   1️⃣ Add all intervals that end **before** `newInterval` starts (no overlap).
//   2️⃣ Merge all intervals that **overlap** with `newInterval`.
//   3️⃣ Add all intervals that start **after** `newInterval` ends.
//
// Why this works:
// - Since input is already sorted and non-overlapping, merging is straightforward.
// - We only modify the range of `newInterval` while overlapping continues.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int index = 0;
        int n = intervals.size();

        // 1️⃣ Add all intervals before `newInterval`
        while (index < n && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index]);
            index++;
        }

        // 2️⃣ Merge all overlapping intervals with `newInterval`
        while (index < n && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        result.push_back(newInterval); // add the merged interval

        // 3️⃣ Add remaining intervals
        while (index < n) {
            result.push_back(intervals[index]);
            index++;
        }

        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Insert + Sort + Merge (O(n log n))
// -----------------------------------------------------------------------------
// Idea:
// - Append `newInterval` into the list.
// - Sort intervals based on start time.
// - Merge like in the classic "merge intervals" problem.
//
// ⚠️ Why it's slower:
// - Sorting adds an O(n log n) overhead, which isn't necessary if the list is already sorted.
// - The first approach avoids this by taking advantage of the sorted property.
//
// Time Complexity: O(n log n)  
// Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Add new interval and sort
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // Merge process
        for (int i = 1; i < intervals.size(); ++i) {
            if (merged.back()[1] >= intervals[i][0]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]); // merge
            } else {
                merged.push_back(intervals[i]); // no overlap
            }
        }

        return merged;
    }
};

/*
📊 Performance Comparison:
| Approach      | Time Complexity | Space Complexity | Explanation                              |
|--------------|------------------|------------------|------------------------------------------|
| Approach 1   | O(n)             | O(n)             | Efficient merging without sorting       |
| Approach 2   | O(n log n)       | O(n)             | Simpler to implement but sorting is costlier |

✅ Approach 1 is optimal when `intervals` are already sorted (as per problem statement).
*/
