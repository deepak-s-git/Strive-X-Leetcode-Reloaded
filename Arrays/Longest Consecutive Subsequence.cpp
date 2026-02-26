/*
Problem: Longest Consecutive Sequence (LeetCode #128)
-----------------------------------------------------
Given an unsorted array of integers `nums`, return the length of the
longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
----------
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive sequence is [1,2,3,4].

Example 2:
----------
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
------------
- 0 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: HashSet (Optimal O(n))
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Store all elements in an unordered_set.
// - Only start counting when current number is the START of a sequence
//   (i.e., num-1 does NOT exist).
// - Then keep extending forward while num+1 exists.
//
// This guarantees each number is visited at most once.
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : s) {
            // Start only if it is the beginning of sequence
            if (s.find(num - 1) == s.end()) {
                int curr = num;
                int currLen = 1;

                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Sorting
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sort the array.
// - Count consecutive increasing numbers.
// - Skip duplicates.
// - Reset count if sequence breaks.
//
// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(1) (ignoring sort space)
// -----------------------------------------------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int currLen = 1, maxLen = 1;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]) {
                if(nums[i] == nums[i - 1] + 1){
                    currLen++;
                } else {
                    maxLen = max(currLen, maxLen);
                    currLen = 1;
                }
            }
        }
        return max(maxLen, currLen);
    }
};


