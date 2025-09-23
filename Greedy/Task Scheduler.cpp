/*
Problem: Task Scheduler (LeetCode #621)
---------------------------------------
You are given a list of tasks (A-Z) and a cooldown period n.  
Each task takes 1 unit of time. Between two same tasks, there must be at least n units idle.  

Return the minimum time required to finish all tasks.

Examples:
---------
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B

Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6

Constraints:
------------
- 1 <= tasks.length <= 10^4
- 0 <= n <= 100
- tasks[i] is an uppercase English letter.
*/


// -----------------------------------------------------------------------------
// Approach : Greedy Formula (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - Let maxFreq = frequency of most frequent task.
// - We must arrange maxFreq - 1 "gaps" between these tasks.
// - Each gap has size n.
// - Idle slots = (maxFreq - 1) * n.
// - Subtract overlap filled by other tasks.
// - If idle > 0, answer = tasks.size() + idle, else tasks.size().
//
// Time Complexity: O(26 log 26) ≈ O(1)
// Space Complexity: O(1)
//
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        sort(begin(freq), end(freq));

        int maxFreq = freq[25];
        int gaps = maxFreq - 1;
        int idle = gaps * n;

        for (int i = 24; i >= 0; i--) {
            idle -= min(gaps, freq[i]);
        }

        return idle > 0 ? tasks.size() + idle : tasks.size();
    }
};
