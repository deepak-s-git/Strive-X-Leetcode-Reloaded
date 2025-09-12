/*
Problem: Longest Consecutive Sequence (LeetCode #128)
-----------------------------------------------------
Given an unsorted array of integers nums, return the length of the longest 
consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Examples:
----------
Input: nums = [100,4,200,1,3,2]
Output: 4   // (sequence: 1,2,3,4)

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9   // (sequence: 0,1,2,3,4,5,6,7,8)

Constraints:
-------------
- 0 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
*/


// -----------------------------------------------------------------------------
// Approach 1: Sorting (Efficient in Practice)
// -----------------------------------------------------------------------------
/*
Idea:
- Sort the array.
- Traverse once, counting lengths of consecutive sequences.
- Skip duplicates carefully.
- Return the longest length found.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) (ignoring sort overhead).

⚡ Note: Although this is O(n log n), it runs faster (~9ms) in practice because:
- `std::sort` is highly optimized (introsort).
- Sorting + linear scan benefits from cache locality (array is contiguous).
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        int currLen = 1, maxLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currLen++;
                } else {
                    maxLen = max(maxLen, currLen);
                    currLen = 1;
                }
            }
        }

        return max(maxLen, currLen);
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Hash Set (Theoretical O(n), Slower in Practice)
// -----------------------------------------------------------------------------
/*
Idea:
- Insert all numbers into an unordered_set.
- A sequence must start at a number `x` such that `x-1` is NOT in the set.
- From each such starting number, extend the sequence by checking x+1, x+2, etc.
- Track the longest length.

Time Complexity: O(n) on average (hash set insert + lookup).
Space Complexity: O(n).

⚠️ Why slower (~94ms vs 9ms for sorting)?
- Hashing overhead (computing hash values, handling collisions, rehashing).
- Poor cache locality: unordered_set stores elements scattered in memory.
- Sorting benefits from contiguous memory + optimized algorithms.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : s) {
            // Only start counting if it's the beginning of a sequence
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
