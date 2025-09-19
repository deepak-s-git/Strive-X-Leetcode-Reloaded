/*
Problem: Peak Index in a Mountain Array (LeetCode #852)
--------------------------------------------------------
An array arr is a mountain if:
- arr.length >= 3
- There exists an index i (0 < i < arr.length - 1) such that:
  arr[0] < arr[1] < ... < arr[i-1] < arr[i] 
  and arr[i] > arr[i+1] > ... > arr[arr.length - 1].

Given a mountain array arr, return the index i of the peak element.

Examples:
----------
Input: arr = [0,2,1,0]
Output: 1

Input: arr = [0,10,5,2]
Output: 1

Constraints:
-------------
- 3 <= arr.length <= 10^5
- 0 <= arr[i] <= 10^6
- arr is guaranteed to be a mountain array
*/


// -----------------------------------------------------------------------------
// Approach 0: Linear Scan
// -----------------------------------------------------------------------------
// Idea:
// - Traverse array and find index where arr[i] > arr[i-1] && arr[i] > arr[i+1].
// - Simple but O(n).
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 1; i < arr.size()-1; i++) {
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                return i;
            }
        }
        return -1; // should never happen
    }
};


// -----------------------------------------------------------------------------
// Approach 1: Binary Search
// -----------------------------------------------------------------------------
// Idea:
// - Peak must exist since array is a mountain.
// - Use binary search between 1 and n-2.
// - If arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1], mid is peak.
// - If arr[mid] > arr[mid-1], move right (increasing slope).
// - Else, move left (decreasing slope).
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid-1] < arr[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1; // guaranteed mountain, so this won't happen
    }
};
