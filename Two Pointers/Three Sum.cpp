/*
Problem: 3Sum (LeetCode #15)
------------------------------
Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, j != k and nums[i] + nums[j] + nums[k] == 0.

Note: The solution set must not contain duplicate triplets.

Examples:
----------
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0,1,1]
Output: []

Input: nums = [0,0,0]
Output: [[0,0,0]]

Constraints:
-------------
- 3 <= nums.length <= 3000
- -10^5 <= nums[i] <= 10^5
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force + Set (O(n^3))
// -----------------------------------------------------------------------------
/*
Idea:
- Check all possible triplets (i, j, k).
- If their sum is 0, sort and insert into a set to avoid duplicates.
- Collect results from the set.

Time Complexity: O(n^3 log m)   (n^3 triplets, log m for set insert)
Space Complexity: O(m)          (storing unique triplets)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> tri = {nums[i], nums[j], nums[k]};
                        sort(tri.begin(), tri.end());
                        if (s.find(tri) == s.end()) {
                            s.insert(tri);
                            ans.push_back(tri);
                        }
                    }
                }
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: HashSet + Deduplication (O(n^2))
// -----------------------------------------------------------------------------
/*
Idea:
- Fix one element nums[i], target = -nums[i].
- Use a hashset to check if there exists a pair summing to target.
- Store triplets in a set to remove duplicates.

Time Complexity: O(n^2 log m) (extra log m from set for duplicates)
Space Complexity: O(n + m)    (hashset + result set)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqTri;

        for (int i=0; i<n; i++) {
            int tar = -nums[i];
            set<int> s;
            for (int j=i+1; j<n; j++) {
                int third = tar - nums[j];
                if (s.find(third) != s.end()) {
                    vector<int> tri = {nums[i], nums[j], third};
                    sort(tri.begin(), tri.end());
                    uniqTri.insert(tri);
                }
                s.insert(nums[j]);
            }
        }
        return vector<vector<int>>(uniqTri.begin(), uniqTri.end());
    }
};


// -----------------------------------------------------------------------------
// Approach 3: Sorting + Two Pointers (Optimal)
// -----------------------------------------------------------------------------
/*
Idea:
- Sort nums.
- Fix nums[i] and use two pointers (j, k) to find pairs with sum = -nums[i].
- Skip duplicates for i and j to avoid repeated triplets.

Time Complexity: O(n^2)   (outer loop + two-pointer scan)
Space Complexity: O(1)    (apart from output)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates

            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while (j < k && nums[j] == nums[j-1]) j++; // skip dup
                }
            }
        }
        return ans;
    }
};
