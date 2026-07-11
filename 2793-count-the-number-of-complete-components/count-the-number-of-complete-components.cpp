class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             int &nodes,
             int &edges){

        vis[node] = 1;

        nodes++;

        edges += adj[node].size();

        for(auto it : adj[node]){

            if(!vis[it]){

                dfs(it, adj, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &it : edges){

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        int ans = 0;

        for(int i=0;i<n;i++){

            if(!vis[i]){

                int nodes = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, nodes, edgeCount);

                edgeCount /= 2;

                if(edgeCount == nodes*(nodes-1)/2)
                    ans++;
            }
        }

        return ans;
    }
};