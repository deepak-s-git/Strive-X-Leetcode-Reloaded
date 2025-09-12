/*
Problem: First Missing Positive (LeetCode #41)
----------------------------------------------
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Examples:
----------
Input: nums = [1,2,0]
Output: 3

Input: nums = [3,4,-1,1]
Output: 2

Input: nums = [7,8,9,11,12]
Output: 1

Constraints:
-------------
- 1 <= nums.length <= 10^5
- -2^31 <= nums[i] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// Brute Force Idea (Not Implemented)
// -----------------------------------------------------------------------------
// Start from 1, check sequentially whether each number exists in nums.
// Use a set or linear search.
// Time: O(n^2) if linear scan for each number, or O(n) with a set.
// Space: O(n) if set is used.


// -----------------------------------------------------------------------------
// Approach 1: Sorting
// -----------------------------------------------------------------------------
/*
Idea:
- Sort the array.
- Traverse from smallest positive integer (1).
- If current element matches target, increment target.
- If we encounter a gap (> target), return target.
- Else return the next target.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1).

⚠️ Does not meet strict O(n) requirement but works fine for interviews.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int target = 1;
        for (int val : nums) {
            if (val > 0 && val == target) {
                target++;
            } else if (val > target) {
                return target;
            }
        }
        return target;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Optimal O(n) In-Place
// -----------------------------------------------------------------------------
/*
Idea:
- Ignore non-positive numbers and numbers > n by replacing them with n+1.
- Use index mapping: for every number x in [1..n], mark presence by
  making nums[x-1] negative.
- Finally, the first index with a positive value means number (i+1) is missing.
- If all indices are marked, answer is n+1.

Time Complexity: O(n)
Space Complexity: O(1) (in-place)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace out-of-range values with n+1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark presence
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: Find first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
