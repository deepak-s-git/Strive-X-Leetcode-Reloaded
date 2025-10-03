/*
Problem: Sort Items by Groups Respecting Dependencies (LeetCode #1203)
-----------------------------------------------------------------------
You have `n` items labeled from `0` to `n - 1` and each belongs to one of `m` groups.  
Some items depend on other items being completed before them.  
You must return an ordering of all items that respects:
1. Item dependencies.
2. Group dependencies (if an item from group A depends on one from group B, then all items in B must come before all in A).

If no valid ordering exists, return an empty array.

Example:
--------
Input:
n = 8, m = 2
group = [-1,-1,1,0,0,1,0,-1]
beforeItems = [
  [],[6],[5],[6],[3,6],[],[],[]
]

Output:
[6,3,4,1,5,2,0,7]

Explanation:
- Item 6 must come before items 1, 3, and 4.
- Item 3 must come before item 4.
- Valid order: [6,3,4,1,5,2,0,7]

Constraints:
------------
- 1 <= m <= n <= 3 * 10^4
- group.length == n
- beforeItems.length == n
- 0 <= beforeItems[i].length <= n - 1
- 0 <= beforeItems[i][j] < n
- All beforeItems[i] are unique.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Two-Level Topological Sort (Groups + Items)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - We need to respect **item dependencies** AND **group dependencies**.
// - If an item from group A depends on one from group B, then **all of B must come before A**.
// - So, we build **two graphs**:
//   1. Item-level graph → to handle item dependencies.
//   2. Group-level graph → to handle group ordering.
//
// 🧠 Steps:
// 1. Assign new group IDs to items with `-1` (unique group for each).
// 2. Build graphs:
//    - `itemAdj`: edges between items.
//    - `groupAdj`: edges between groups (only if dependency crosses groups).
// 3. Perform **topological sort twice**:
//    - Once on the `group graph`
//    - Once on the `item graph`
// 4. Merge results: for each sorted group, append its items in sorted order.
//
// ⏱️ Time Complexity: O(n + e) — where `e` is total dependencies.
// 📦 Space Complexity: O(n + e) — adjacency lists and indegree arrays.
// -----------------------------------------------------------------------------

class Solution {
public:

    // 📍 DFS-based Topological Sort
    vector<int> DFS(auto& adj, vector<int>& deg, int sz) {
        vector<int> result;
        function<void(int)> dfs = [&](int node){
            result.push_back(node);
            deg[node] = -1; // mark visited
            for(int neighbor : adj[node]){
                if(--deg[neighbor] == 0)
                    dfs(neighbor);
            }
        };

        for(int i = 0; i < sz; i++)
            if(deg[i] == 0)
                dfs(i);

        for(int i = 0; i < sz; i++)
            if(deg[i] > 0) return {}; // ❌ cycle detected

        return result;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 🛠️ Step 1: Assign unique groups to ungrouped items
        for(int i = 0; i < n; i++)
            if(group[i] == -1) group[i] = m++;

        // 📦 Build item and group graphs
        vector<vector<int>> itemAdj(n);
        vector<int> itemDeg(n, 0);
        vector<unordered_set<int>> groupAdjSet(m);
        vector<int> groupDeg(m, 0);

        for(int i = 0; i < n; i++){
            int toGroup = group[i];
            for(int from : beforeItems[i]){
                int fromGroup = group[from];
                
                // 🔁 Add group edge (only if dependency crosses groups)
                if(toGroup != fromGroup && groupAdjSet[fromGroup].count(toGroup) == 0){
                    groupAdjSet[fromGroup].insert(toGroup);
                    groupDeg[toGroup]++;
                }

                // 📎 Add item edge
                itemAdj[from].push_back(i);
                itemDeg[i]++;
            }
        }

        // 🔍 Step 2: Topologically sort groups and items
        vector<int> sortedGroups = DFS(groupAdjSet, groupDeg, m);
        vector<int> sortedItems = DFS(itemAdj, itemDeg, n);

        if(sortedGroups.empty() || sortedItems.empty()) return {}; // ❌ Cycle detected

        // 🧩 Step 3: Organize items by group
        vector<vector<int>> itemsInGroup(m);
        for(int item : sortedItems)
            itemsInGroup[group[item]].push_back(item);

        // ✅ Step 4: Merge final result based on group order
        vector<int> ans;
        for(int grp : sortedGroups)
            for(int item : itemsInGroup[grp])
                ans.push_back(item);

        return ans;
    }
};
