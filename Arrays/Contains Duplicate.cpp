/*
Problem: Contains Duplicate (LeetCode #217)
------------------------------------------
Given an integer array `nums`, return true if any value appears
at least twice in the array, and return false if every element is distinct.

Example 1:
----------
Input:  nums = [1,2,3,1]
Output: true

Example 2:
----------
Input:  nums = [1,2,3,4]
Output: false

Example 3:
----------
Input:  nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
------------
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Sorting + Adjacent Check
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sort the array.
// - If any adjacent elements are equal → duplicate exists.
//
// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(1) (ignoring sort recursion stack)
// -----------------------------------------------------------------------------
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};


/*
---------------------------------------------------------------------------
✅ Approach 2: Using Unordered Set (Optimal & Clean)
---------------------------------------------------------------------------
🔹 Intuition:
- Insert elements into a hash set.
- If element already exists → duplicate found.

⏱ Time Complexity: O(n)
📦 Space Complexity: O(n)
---------------------------------------------------------------------------
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (s.count(num) > 0) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};


/*
---------------------------------------------------------------------------
✅ Approach 3: Using Unordered Map (Frequency Count)
---------------------------------------------------------------------------
🔹 Intuition:
- Count occurrences using hashmap.
- If frequency ≥ 1 before increment → duplicate found.

⏱ Time Complexity: O(n)
📦 Space Complexity: O(n)
---------------------------------------------------------------------------
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            if (freq[num] >= 1)
                return true;
            freq[num]++;
        }
        return false;
    }
};