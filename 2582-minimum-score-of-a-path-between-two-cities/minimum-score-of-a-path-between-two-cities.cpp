class Solution {
private:
    int ans=INT_MAX;
    void dfs(int node, vector<pair<int,int>>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;
            //update the min.edge
            ans=min(ans,wt);
            if(!vis[adjnode]){
                dfs(adjnode,adj,vis);
            }
        }

    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        //creating the adj list
        vector<pair<int,int>>adj[n+1];
        for(auto &it :roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
        //creating the vis array
        vector<int>vis(n+1,0);
        dfs(1,adj,vis);
        return ans;

    }
};