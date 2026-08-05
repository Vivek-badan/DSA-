class Solution {
public:

    // DFS to mark all suspicious methods
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Step 1: Create Adjacency List
        vector<vector<int>> adj(n);

        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }

        // Step 2: Mark all suspicious methods
        vector<int> vis(n, 0);

        dfs(k, adj, vis);

        // Step 3:
        // Check if any non-suspicious method
        // invokes a suspicious method.

        for (auto &it : invocations) {

            int u = it[0];
            int v = it[1];

            if (vis[u] == 0 && vis[v] == 1) {

                // Removal impossible
                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // Step 4:
        // Safe to remove suspicious methods.

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};