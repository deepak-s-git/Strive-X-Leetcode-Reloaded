/*
Problem: Task Scheduler (LeetCode #621)
----------------------------------------
Given a list of tasks represented by uppercase letters and a non-negative integer `cooldown`,
return the minimum number of units of time the CPU will take to finish all tasks. 
The same task must be separated by at least `cooldown` units of time.

Example:
--------
Input: tasks = ['A','A','A','B','B','B'], cooldown = 2
Output: 8

Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
Total time = 8

Constraints:
------------
- 1 <= tasks.length <= 10^4
- tasks[i] is an uppercase English letter.
- 0 <= cooldown <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Greedy + Max-Heap
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Always execute the task with the highest remaining frequency.
// - After executing a task, it cannot be executed again for `cooldown` intervals.
// - Use a max-heap to track task frequencies and simulate intervals.
// - Keep a temporary list of tasks processed in this cycle and push back to heap if remaining.
//
// ⏱️ Time Complexity: O(N log 26) ≈ O(N) — heap size max 26
// 📦 Space Complexity: O(26) — for frequency array and heap
// -----------------------------------------------------------------------------
class Solution {
public:
    int leastInterval(vector<char>& tasks, int cooldown) {
        vector<int> freq(26, 0);
        for (char task : tasks) freq[task - 'A']++;

        priority_queue<int> maxHeap;
        for (int f : freq) if (f) maxHeap.push(f);

        int totalTime = 0;
        while (!maxHeap.empty()) {
            vector<int> pending;
            int slots = cooldown + 1; // max tasks we can execute in this cycle

            // execute up to cooldown+1 tasks in this cycle
            while (slots && !maxHeap.empty()) {
                int cnt = maxHeap.top(); maxHeap.pop();
                if (cnt > 1) pending.push_back(cnt - 1);
                totalTime++;
                slots--;
            }

            // push remaining tasks back into heap
            for (int p : pending) maxHeap.push(p);

            if (maxHeap.empty()) break;

            // add idle time if there are still tasks left
            totalTime += slots;
        }
        return totalTime;
    }
};
