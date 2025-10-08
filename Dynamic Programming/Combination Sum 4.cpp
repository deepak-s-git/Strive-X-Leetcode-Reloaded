/*
🎯 Problem: Combination Sum IV (LeetCode 377)

Given an array of distinct integers `nums` and a target integer `target`, 
return the **number of possible combinations** that add up to `target`.

⚠️ Note:
- Different sequences are counted as different combinations.
- The order of elements matters.

📥 Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation: 
The possible combinations are:
(1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2), (1,3), (3,1)

📥 Example 2:
Input: nums = [9], target = 3
Output: 0

⚙️ Constraints:
- 1 <= nums.length <= 200
- 1 <= nums[i] <= 1000
- All elements of nums are distinct.
- 1 <= target <= 1000
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (Bottom-Up)
   ================================================================
   🔍 Intuition:
   - Use `ways[sum]` to store the number of ways to make sum = `sum`.
   - Base Case: `ways[0] = 1` (1 way to form 0: by choosing nothing).
   - For each total from 1 to `target`, check each `num`:
     - If `num` can be used (`sum - num >= 0`), add ways of `sum - num`.

   🧠 Transition Formula:
   ways[sum] += ways[sum - num]  if (sum - num >= 0)

   📊 Dry Run:
   nums = [1,2,3], target = 4

   ways[0] = 1
   sum=1: ways[1] = ways[0] = 1
   sum=2: ways[2] = ways[1] + ways[0] = 2
   sum=3: ways[3] = ways[2] + ways[1] + ways[0] = 4
   sum=4: ways[4] = ways[3] + ways[2] + ways[1] = 7 ✅

   ⏱️ Complexity:
   - Time:  O(target * n)   where n = size of nums
   - Space: O(target)       (for the DP array)
================================================================ */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> ways(target + 1, 0); 
        ways[0] = 1; // Base case: 1 way to make sum = 0

        for (int sum = 1; sum <= target; ++sum) {
            for (int num : nums) {
                if (sum - num >= 0) {
                    ways[sum] += ways[sum - num];
                }
            }
        }

        return ways[target];
    }
};
