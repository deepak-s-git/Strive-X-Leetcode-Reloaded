// 🏷️ LeetCode 207 - Course Schedule
// 📂 Repository-style: Topological Sort (Kahn’s Algorithm - BFS)
// ---------------------------------------------------------------
// ✅ Approach: BFS Topological Sort
// ✅ Idea: A course can only be taken when all its prerequisites are completed.
// ✅ Goal: Detect if there’s a cycle in the directed graph of prerequisites.
// ---------------------------------------------------------------
// 📌 Graph Representation: Adjacency List
// 📌 If all courses can be completed (no cycle) → return true
// 📌 If there’s a cycle → return false

class Solution {
public:
    bool canFinish(int totalCourses, vector<vector<int>>& prereqList) {
        // -----------------------------------------------
        // Step 1: Build the graph and compute in-degree
        // -----------------------------------------------
        vector<int> courseGraph[totalCourses];   // Adjacency list for each course
        vector<int> inDegree(totalCourses, 0);   // Track number of prerequisites for each course

        // Build graph and update in-degree
        for (auto &edge : prereqList) {
            int course = edge[0];   // Course to take
            int pre = edge[1];      // Prerequisite course
            courseGraph[pre].push_back(course);  // Directed edge: pre -> course
            inDegree[course]++;                  // Increase in-degree for this course
        }

        // -----------------------------------------------
        // Step 2: Push all nodes with 0 in-degree into queue
        // -----------------------------------------------
        queue<int> zeroDegree;
        for (int i = 0; i < totalCourses; i++) {
            if (inDegree[i] == 0) zeroDegree.push(i);  // Can be taken immediately
        }

        // -----------------------------------------------
        // Step 3: Perform BFS (Kahn’s Algorithm)
        // -----------------------------------------------
        int completed = 0;  // Count of courses successfully processed

        while (!zeroDegree.empty()) {
            int current = zeroDegree.front();
            zeroDegree.pop();
            completed++;  // One course finished

            // Reduce in-degree of adjacent courses
            for (int nextCourse : courseGraph[current]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    zeroDegree.push(nextCourse);  // Next course can now be taken
                }
            }
        }

        // -----------------------------------------------
        // Step 4: Check if all courses are completed
        // -----------------------------------------------
        return completed == totalCourses; // True if no cycle (i.e., all courses done)
    }
};
