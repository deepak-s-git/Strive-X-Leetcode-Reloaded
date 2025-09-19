/*
Problem: Find K Closest Elements (LeetCode #658)
------------------------------------------------
Given a sorted integer array arr, two integers k and x, return the k closest 
integers to x in the array. The result should also be sorted in ascending order.

The absolute difference between two integers a and b is |a - b|.

Examples:
---------
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
-------------
- 1 <= k <= arr.length
- 1 <= arr.length <= 10^4
- arr is sorted in ascending order
- -10^4 <= arr[i], x <= 10^4
*/


// -----------------------------------------------------------------------------
// Approach: Binary Search + Two Pointers Expansion
// -----------------------------------------------------------------------------
// Idea:
// - Use binary search (`lower_bound`) to find the insertion index of x in arr.
// - Then expand outward with two pointers (`l`, `h`) to pick the closer elements.
// - At each step, compare distance to x and move the pointer that gives 
//   the closer element.
// - Finally, return the subarray [l+1, h).
//
// Time Complexity: O(log n + k)   // binary search + expanding k elements
// Space Complexity: O(1)          // just pointers
//
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int h = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = h - 1;

        while (k--) {
            if (l < 0) {             
                h++;
            } else if (h >= arr.size()) { 
                l--;
            } else if (x - arr[l] > arr[h] - x) {
                h++;
            } else {
                l--;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }
};
