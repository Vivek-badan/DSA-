class Solution {
public:
    void dfs(int node ,vector<vector<int>>& isConnected, vector<int>&vis){
        int n =isConnected.size();
        vis[node]=1;
        for(int j=0;j<n;j++){
            if(isConnected[node][j]==1 && vis[j]==0){
                dfs(j,isConnected,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =isConnected.size();
        int provinces=0;
        vector<int>vis(n,0);
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                provinces++;
                dfs(i,isConnected,vis);
            }
        }
        return provinces;
        
    }
};