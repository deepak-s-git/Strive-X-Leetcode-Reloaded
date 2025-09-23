/*
Problem: Course Schedule III (LeetCode #630)
---------------------------------------------
Given an array `courses` where `courses[i] = [durationi, lastDayi]`:  
- `durationi` is the time to complete the course.  
- `lastDayi` is the last day by which the course must be finished.  

Return the maximum number of courses you can take.

Examples:
---------
Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]  
Output: 3  

Input: courses = [[1,2]]  
Output: 1  

Constraints:
------------
- 1 <= courses.length <= 10^4  
- 1 <= durationi, lastDayi <= 10^4  
*/


// -----------------------------------------------------------------------------
// Approach: Greedy + Max Heap (Simplified Comparator)
// -----------------------------------------------------------------------------
// Idea:
// 1. Sort courses by end day (`lastDay`) using a lambda comparator.
// 2. Maintain total time spent and a max-heap of course durations.
// 3. Take a course if it fits in time, else replace the longest duration course
//    in the heap if the current one is shorter.
//
// Time Complexity: O(n log n) (sorting + heap operations)  
// Space Complexity: O(n) (max-heap)
// -----------------------------------------------------------------------------
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Step 1: sort courses by end day
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap; // stores durations of selected courses
        int time = 0;                // total time spent on courses

        for (auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            // Step 2a: take the course if it fits
            if (time + duration <= lastDay) {
                time += duration;
                maxHeap.push(duration);
            } 
            // Step 2b: replace the longest course if current is shorter
            else if (!maxHeap.empty() && maxHeap.top() > duration) {
                time += duration - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(duration);
            }
        }

        return maxHeap.size(); // max number of courses taken
    }
};
