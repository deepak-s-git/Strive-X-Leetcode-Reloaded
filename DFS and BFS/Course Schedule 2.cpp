/*
Problem: Course Schedule II (LeetCode #210)
--------------------------------------------
There are `numCourses` courses labeled from `0` to `numCourses - 1`. 
Each course may have prerequisites given as a list of pairs `[a, b]`, 
where course `a` depends on course `b` (you must take `b` before `a`).

Your task is to return a valid ordering of courses you can take 
to finish all courses. If it’s not possible (due to a cycle), return an empty list.

Example:
--------
Input:
numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]

Output:
[0,1,2,3]
Explanation:
- Course 0 has no prerequisites, so we take it first.
- Courses 1 and 2 depend on 0, so we take them next.
- Course 3 depends on both 1 and 2, so it comes last.

Constraints:
------------
- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= numCourses * (numCourses - 1)
- prerequisites[i].length == 2
- All prerequisite pairs are unique
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Topological Sort (Kahn's Algorithm - BFS)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - This is a classic "Topological Ordering" problem on a Directed Acyclic Graph (DAG).
// - We represent courses as nodes and prerequisites as directed edges.
// - If a valid order exists (graph is a DAG), we can find it using **Kahn's algorithm**.
// - If there’s a cycle (not all nodes processed), return an empty list.
//
// ⚙️ Steps:
// 1. Build adjacency list for the graph and compute indegrees for each course.
// 2. Push all courses with indegree 0 (no prerequisites) into a queue.
// 3. Pop courses from the queue, add them to the order, and reduce indegree of neighbors.
// 4. If all courses are processed, return the order. Otherwise, return {}.
//
// ⏱️ Time Complexity: O(V + E) – each node and edge is processed once.
// 📦 Space Complexity: O(V + E) – adjacency list + indegree + queue.
// -----------------------------------------------------------------------------


class Solution {
public:
    // 📌 Perform Topological Sort using Kahn's Algorithm
    bool topoSort(vector<vector<int>> &graph, int n, vector<int> &indeg, vector<int> &order) {
        queue<int> q;

        // 🔍 Step 1: Add all nodes with indegree 0 to queue
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        int processed = 0;
        // 🔁 Step 2: Process nodes in topological order
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            processed++;

            // 🛠️ Step 3: Reduce indegree of neighbors
            for (auto v : graph[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        // ✅ Return true if we processed all nodes (no cycle)
        return processed == n;
    }

    // 🎯 Main function: returns valid course order or empty list
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);    // adjacency list
        vector<int> indeg(numCourses, 0);         // indegree of each course

        // 📦 Build the graph and indegree array
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        vector<int> order;
        // ✅ Try topological sorting
        if (topoSort(graph, numCourses, indeg, order)) 
            return order;

        // ❌ Cycle detected: no valid ordering
        return {};
    }
};
