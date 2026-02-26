/*
Problem: First Missing Positive (LeetCode #41)
----------------------------------------------
Given an unsorted integer array `nums`, return the smallest missing
positive integer.

You must implement an algorithm that runs in O(n) time and uses
constant extra space.

Example 1:
----------
Input: nums = [1,2,0]
Output: 3

Example 2:
----------
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
----------
Input: nums = [7,8,9,11,12]
Output: 1

Constraints:
------------
- 1 <= nums.length <= 10^5
- -2^31 <= nums[i] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Sorting
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sort the array.
// - Start checking from target = 1.
// - If current value equals target → increment target.
// - If current value becomes greater than target → return target.
//
// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(1) (ignoring sort space)
// -----------------------------------------------------------------------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int target = 1;

        for(int val : nums){
            if(val > 0 && val == target){
                target++;
            } else if(val > target){
                return target;
            }
        }
        return target;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Index Marking (Optimal O(n) Time, O(1) Space)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - The answer must lie in range [1, n+1].
// - Ignore negatives and numbers > n (replace with n+1).
// - Use index marking technique:
//     For number x → mark index (x-1) as negative.
// - First index which remains positive → missing number.
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace invalid numbers
        for(int i = 0; i < n; i++){
            if(nums[i] > n || nums[i] <= 0){
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark existing numbers
        for(int i = 0; i < n; i++){
            int num = abs(nums[i]);
            if(num <= n){
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: Find first positive index
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }

        return n + 1;
    }
};