/*
Problem: Jump Game (LeetCode #55)
---------------------------------
You are given an integer array nums. Initially positioned at the first index, 
each element in nums represents your maximum jump length at that position.

Return true if you can reach the last index, otherwise false.

Examples:
---------
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3, but its max jump length is 0.

Constraints:
------------
- 1 <= nums.length <= 10^4
- 0 <= nums[i] <= 10^5
*/



// -----------------------------------------------------------------------------
// Approach : Greedy (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - Track the furthest index we can reach (maxJump).
// - Iterate through nums:
//      - If current index > maxJump, we are stuck -> return false.
//      - Update maxJump = max(maxJump, i + nums[i]).
// - If we finish the loop, we can reach the end.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxJump) return false;
            maxJump = max(maxJump, i + nums[i]);
        }
        return true;
    }
};
