/*
Problem: Two Sum (LeetCode #1)
-----------------------------------------------
Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.

Examples:
----------
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
-------------
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force
// -----------------------------------------------------------------------------
/*
Idea:
- Try every possible pair (i, j).
- If nums[i] + nums[j] == target, return indices.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Hash Map (Optimized)
// -----------------------------------------------------------------------------
/*
Idea:
- Use a hashmap to store numbers and their indices.
- For each nums[i], check if (target - nums[i]) already exists in the map.
- If yes → return indices.
- If not → store nums[i] in map for future.

Time Complexity: O(n) (each element looked up/inserted once)
Space Complexity: O(n) (hashmap storage)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int sec = target - nums[i];
            if (m.find(sec) != m.end()) {
                return {i, m[sec]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};


// -----------------------------------------------------------------------------
// Approach 3: Sorting + Two Pointers
// -----------------------------------------------------------------------------
/*
Idea:
- Store (value, index) pairs in an array.
- Sort by value.
- Use two pointers (left, right) to find two numbers that sum to target.
- Return their original indices.

⚠️ Important:
- Sorting destroys original order, so we must store indices in pairs.

Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(n) (extra array to store value-index pairs)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;
        while (i < j) {
            int sum = arr[i].first + arr[j].first;
            if (sum == target) {
                return {arr[i].second, arr[j].second};
            }
            else if (sum > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return {};
    }
};
