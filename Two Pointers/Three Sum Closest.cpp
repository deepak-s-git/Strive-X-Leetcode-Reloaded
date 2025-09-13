/*
Problem: 3Sum Closest (LeetCode #16)
-------------------------------------
Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Examples:
----------
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. 
(-1 + 2 + 1 = 2).

Constraints:
-------------
- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -10^4 <= target <= 10^4
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force (O(n^3))
// -----------------------------------------------------------------------------
/*
Idea:
- Try all triplets (i, j, k).
- Track the one whose sum is closest to target.

Time Complexity: O(n^3)
Space Complexity: O(1)

Note: Works but will TLE for n up to 500.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = INT_MAX / 2; // large number

        for (int i=0; i<nums.size()-2; i++) {
            for (int j=i+1; j<nums.size()-1; j++) {
                for (int k=j+1; k<nums.size(); k++) {
                    int curr_sum = nums[i] + nums[j] + nums[k];
                    if (abs(curr_sum - target) < abs(closest_sum - target)) {
                        closest_sum = curr_sum;
                    }
                }
            }
        }
        return closest_sum;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Sorting + Two Pointers (Optimal O(n^2))
// -----------------------------------------------------------------------------
/*
Idea:
- Sort nums.
- Fix one number nums[i].
- Use two pointers (left, right) to find best pair that brings sum close to target.
- Update closest_sum whenever we find a closer one.
- If we ever hit exactly target, return immediately.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = INT_MAX / 2; // large number

        for (int i=0; i<nums.size() - 2; i++) {
            int left = i+1, right = nums.size() - 1;
            while (left < right) {
                int curr_sum = nums[i] + nums[left] + nums[right];

                if (abs(curr_sum - target) < abs(closest_sum - target)) {
                    closest_sum = curr_sum;
                }

                if (curr_sum < target) {
                    left++;
                } else if (curr_sum > target) {
                    right--;
                } else {
                    return curr_sum; // exact match found
                }
            }
        }
        return closest_sum;
    }
};
