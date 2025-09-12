/*
Problem: Find All Duplicates in an Array (LeetCode #442)
---------------------------------------------------------
Given an integer array nums of length n where each element nums[i] is in the 
range [1, n], return all the integers that appear twice in nums.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Examples:
----------
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Input: nums = [1,1,2]
Output: [1]

Constraints:
-------------
- n == nums.length
- 1 <= n <= 10^5
- 1 <= nums[i] <= n
*/


// -----------------------------------------------------------------------------
// Approach 0: Brute Force (Nested Loops)
// -----------------------------------------------------------------------------
// Idea:
// - For each element, scan the rest of the array to check for duplicates.
// - Add to result if found.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Not efficient; only for illustration.
//
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 1: Sorting
// -----------------------------------------------------------------------------
// Idea:
// - Sort the array, then check adjacent elements for equality.
// - Collect duplicates.
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) (ignoring sort stack space)
// Violates "constant extra space" constraint.
//
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Hash Map / Frequency Counting
// -----------------------------------------------------------------------------
// Idea:
// - Count frequency of each number using a hash map.
// - Collect numbers with frequency == 2.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// Violates "O(1) extra space" constraint.
//
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int val : nums) {
            freq[val]++;
        }
        for (auto p : freq) {
            if (p.second == 2) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 3: Index Marking (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - Use the fact that nums[i] is in range [1, n].
// - For each number x = abs(nums[i]), go to index (x-1).
//   - If nums[x-1] is already negative → x is duplicate, add to result.
//   - Else, flip nums[x-1] negative to mark it visited.
// - Restores O(1) extra space usage.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            if (nums[x-1] < 0) {
                ans.push_back(x);
            }
            nums[x-1] *= -1; // mark as visited
        }
        return ans;
    }
};
