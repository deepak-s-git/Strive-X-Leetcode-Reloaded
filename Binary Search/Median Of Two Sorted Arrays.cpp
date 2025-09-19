/*
Problem: Median of Two Sorted Arrays (LeetCode #4)
-------------------------------------------------
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log(min(m, n))).

Examples:
---------
Input: nums1 = [1,3], nums2 = [2]
Output: 2.0

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.5

Constraints:
-------------
- nums1.length == m, nums2.length == n
- 0 <= m, n <= 1000
- 1 <= m + n <= 2000
- -10^6 <= nums1[i], nums2[i] <= 10^6
*/


// -----------------------------------------------------------------------------
// Approach: Binary Search on Partition
// -----------------------------------------------------------------------------
// Idea:
// - Ensure nums1 is the smaller array (for binary search efficiency).
// - Partition nums1 at index partitionX, then partition nums2 at partitionY
//   such that left side has (m+n+1)/2 elements.
// - We want: max of left side <= min of right side.
//   i.e., maxX <= minY AND maxY <= minX
// - If condition holds, median can be calculated.
//   - Odd total length → median is max(left parts).
//   - Even total length → median is average of max(left) and min(right).
// - If maxX > minY → move binary search left.
//   Else → move right.
//
// Time Complexity: O(log(min(m, n)))
// Space Complexity: O(1)
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            // Left and right boundary values
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            // Check if correct partition
            if (maxX <= minY && maxY <= minX) {
                // Even total length
                if ((m + n) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } 
                // Odd total length
                else {
                    return max(maxX, maxY);
                }
            } 
            // Too far right in nums1, move left
            else if (maxX > minY) {
                high = partitionX - 1;
            } 
            // Too far left in nums1, move right
            else {
                low = partitionX + 1;
            }
        }
        return -1; // Should never reach here
    }
};
