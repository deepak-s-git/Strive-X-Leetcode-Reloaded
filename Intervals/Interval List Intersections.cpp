/*
Problem: Interval List Intersections (LeetCode #986)
----------------------------------------------------
You are given two lists of closed intervals, `firstList` and `secondList`, where each list is sorted 
in non-decreasing order and intervals do not overlap within the same list.

Return the intersection of these two interval lists.

Examples:
---------
Input:
firstList  = [[0,2],[5,10],[13,23],[24,25]]
secondList = [[1,5],[8,12],[15,24],[25,26]]
Output:
[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Explanation:
- [0,2] ∩ [1,5] = [1,2]
- [5,10] ∩ [1,5] = [5,5]
- [5,10] ∩ [8,12] = [8,10]
- [13,23] ∩ [15,24] = [15,23]
- [24,25] ∩ [15,24] = [24,24]
- [24,25] ∩ [25,26] = [25,25]

Constraints:
------------
- 0 <= firstList.length, secondList.length <= 1000
- firstList[i].length == secondList[j].length == 2
- 0 <= start <= end <= 10^9
- Intervals in each list are non-overlapping and sorted.
*/


// ✅ Approach: Two-Pointer Merge Technique
// ----------------------------------------
// 1. Use two pointers `i` and `j` for `firstList` and `secondList`.
// 2. At each step, find the intersection (if any) between firstList[i] and secondList[j]:
//    - Start of intersection: max(start1, start2)
//    - End of intersection:   min(end1, end2)
//    - If valid (start <= end), push to result.
// 3. Move the pointer of the interval that ends first (to find possible overlaps with the next one).
//
// Why this works:
// - Since both lists are sorted and non-overlapping internally, a linear scan with two pointers 
//   guarantees that all possible intersections are checked.
//
// Time Complexity: O(m + n)  → m = firstList.size(), n = secondList.size()
// Space Complexity: O(1)     → ignoring result vector
//
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0; 

        // 🔹 Two-pointer scan
        while (i < firstList.size() && j < secondList.size()) {
            int left  = max(firstList[i][0], secondList[j][0]);  // start of overlap
            int right = min(firstList[i][1], secondList[j][1]);  // end of overlap

            // ✅ If they intersect, add to result
            if (left <= right) {
                res.push_back({left, right});
            }

            // 🔁 Move the pointer of the interval that finishes first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};
