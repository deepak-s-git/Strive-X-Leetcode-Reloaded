/*
Problem: Container With Most Water (LeetCode #11)
-------------------------------------------------
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.

Examples:
---------
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Input: height = [1,1]
Output: 1

Constraints:
------------
- n == height.length
- 2 <= n <= 10^5
- 0 <= height[i] <= 10^4
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force (O(n^2))
// -----------------------------------------------------------------------------
/*
Idea:
- For every pair (i, j), calculate the water container area:
    width = j - i
    height = min(height[i], height[j])
    area = width * height
- Keep track of the maximum.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWtr = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = j - i;
                int h = min(height[i], height[j]);
                int currWtr = w * h;
                maxWtr = max(maxWtr, currWtr);
            }
        }
        return maxWtr;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Two-Pointer Technique (Optimal, O(n))
// -----------------------------------------------------------------------------
/*
Idea:
- Start with two pointers: left = 0, right = n-1.
- At each step, calculate area with lines at left and right.
- Move the pointer corresponding to the smaller height inward 
  (since width decreases, we must try to find a taller line to maximize area).

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWtr = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int currWtr = w * h;
            maxWtr = max(maxWtr, currWtr);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxWtr;
    }
};
