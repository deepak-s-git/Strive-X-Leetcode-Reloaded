/*
💠 Problem: Number of Longest Increasing Subsequence (LeetCode 673)

Given an integer array `nums`, return the number of **longest increasing subsequences** in it.  
Notice that the sequence has to be **strictly increasing**.

📥 Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1,3,4,7] and [1,3,5,7].

📥 Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the LIS is 1, and there are 5 such subsequences.

⚙️ Constraints:
- 1 <= nums.length <= 2000
- -10⁶ <= nums[i] <= 10⁶
*/


/* ================================================================
   ✅ Approach 1: Dynamic Programming (Length + Count Arrays)
   ================================================================
   🔍 Intuition:
   - Maintain two arrays:
       ➤ `lisLength[i]`: Length of longest increasing subsequence ending at index `i`
       ➤ `lisCount[i]`:  Number of such LIS ending at index `i`
   - For each pair (prev < curr):
       - If nums[curr] > nums[prev], we can extend the LIS from `prev` to `curr`.
       - Update length and count accordingly.
   - Finally, sum up the counts for indices where LIS length == maximum LIS length.

   ⏱️ Complexity:
   - Time:  O(n²)
   - Space: O(n)
================================================================ */

class Solution {
public:
    int findNumberOfLIS(vector<int>& sequence) {
        int size = sequence.size();
        if (size == 0) return 0;

        vector<int> lisLength(size, 1);  // Length of LIS ending at each index
        vector<int> lisCount(size, 1);   // Count of LIS ending at each index
        
        int longest = 1;
        
        for (int curr = 0; curr < size; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (sequence[curr] > sequence[prev]) {
                    if (lisLength[prev] + 1 > lisLength[curr]) {
                        lisLength[curr] = lisLength[prev] + 1;
                        lisCount[curr] = lisCount[prev];
                    } 
                    else if (lisLength[prev] + 1 == lisLength[curr]) {
                        lisCount[curr] += lisCount[prev];
                    }
                }
            }
            longest = max(longest, lisLength[curr]);
        }
        
        int totalCount = 0;
        for (int i = 0; i < size; i++) {
            if (lisLength[i] == longest) {
                totalCount += lisCount[i];
            }
        }

        return totalCount;
    }
};
