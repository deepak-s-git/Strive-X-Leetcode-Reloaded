/*
🔎 Problem: Range Sum Query - Immutable (LeetCode 303)

Given an integer array `nums`, handle multiple queries of the following type:
- sumRange(left, right): Return the sum of the elements of nums between indices left and right inclusive 
  (i.e., nums[left] + nums[left+1] + ... + nums[right]).

📥 Example:
Input:
nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1   // -2 + 0 + 3
sumRange(2, 5) -> -1  // 3 - 5 + 2 - 1
sumRange(0, 5) -> -3  // -2 + 0 + 3 - 5 + 2 - 1

⚙️ Constraints:
- 1 <= nums.length <= 10^4
- -10^5 <= nums[i] <= 10^5
- 0 <= left <= right < nums.length
*/


/* ================================================================
   ✅ Approach 1: Prefix Sum Precomputation
   ================================================================
   🔍 Intuition:
   - To efficiently answer multiple range sum queries, we can precompute the prefix sums.
   - prefixSum[i] = sum of nums[0] + nums[1] + ... + nums[i]
   - Then any range sum can be computed in O(1):
     sumRange(left, right) = prefixSum[right] - prefixSum[left - 1]

   🧠 Steps:
   1. Precompute prefix sums once in the constructor.
   2. Answer queries in O(1) by subtracting two prefix sums.

   📊 Example:
   nums = [1, 2, 3, 4]
   prefixSum = [1, 3, 6, 10]

   sumRange(1, 3) = prefixSum[3] - prefixSum[0] = 10 - 1 = 9

   ⏱️ Complexity:
   - Time:
       - Preprocessing: O(n)
       - Each query: O(1)
   - Space: O(n) (for prefixSum array)
================================================================ */

class NumArray {
private:
    int size;
    vector<int> prefixSum;

public:
    // Constructor: Precompute prefix sums
    NumArray(vector<int>& nums) {
        size = nums.size();
        prefixSum = vector<int>(size, 0);

        if (size > 0) prefixSum[0] = nums[0];

        for (int i = 1; i < size; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }

    // Query: Return sum of nums[left..right]
    int sumRange(int left, int right) {
        if (left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};
