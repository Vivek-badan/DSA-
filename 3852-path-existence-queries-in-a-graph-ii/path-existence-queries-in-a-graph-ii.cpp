class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        // original index -> sorted index
        vector<int> pos(n);

        for(int i = 0; i < n; i++){
            pos[arr[i].second] = i;
        }

        // next[i] = farthest node reachable in one move
        vector<int> next(n);

        int j = 0;

        for(int i = 0; i < n; i++){

            while(j + 1 < n && arr[j + 1].first - arr[i].first <= maxDiff){
                j++;
            }

            next[i] = j;
        }

        int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++){
            up[0][i] = next[i];
        }

        for(int k = 1; k < LOG; k++){

            for(int i = 0; i < n; i++){

                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        vector<int> ans;

        for(auto &it : queries){

            int u = pos[it[0]];
            int v = pos[it[1]];

            if(u > v)
                swap(u, v);

            if(u == v){
                ans.push_back(0);
                continue;
            }

            if(next[u] == u){
                ans.push_back(-1);
                continue;
            }

            int jumps = 0;
            int cur = u;

            for(int k = LOG - 1; k >= 0; k--){

                if(up[k][cur] < v){

                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            if(next[cur] < v)
                ans.push_back(-1);
            else
                ans.push_back(jumps + 1);
        }

        return ans;
    }
};