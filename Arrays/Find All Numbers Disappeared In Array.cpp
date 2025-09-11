/*
Problem: Find All Numbers Disappeared in an Array (LeetCode #448)
------------------------------------------------------------------
Given an array nums of n integers where nums[i] is in the range [1, n],
return an array of all the integers in the range [1, n] that do not appear in nums.

Examples:
----------
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Input: nums = [1,1]
Output: [2]

Constraints:
-------------
- n == nums.length
- 1 <= n <= 10^5
- 1 <= nums[i] <= n
*/


// -----------------------------------------------------------------------------
// Approach 1: HashSet
// -----------------------------------------------------------------------------
/*
Idea:
- Insert all numbers from nums into a set.
- Iterate from 1 to n, and check which numbers are missing.
- Collect them into the result vector.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) {
                v.push_back(i);
            }
        }
        return v;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: In-Place Marking
// -----------------------------------------------------------------------------
/*
Idea:
- Use the input array itself to track seen numbers.
- For each value x, mark nums[x-1] as negative (indicating x was seen).
- After processing, indices with positive values correspond to missing numbers.
- This works because values are guaranteed to be in the range [1, n].

Time Complexity: O(n)
Space Complexity: O(1) (ignoring output vector)

Note: The input array nums is modified.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];  // mark as visited
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {           // unvisited index → missing number
                v.push_back(i + 1);
            }
        }

        return v;
    }
};
