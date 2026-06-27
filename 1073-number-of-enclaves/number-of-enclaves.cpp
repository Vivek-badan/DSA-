class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //STEP-1 ( Check the boundary 1's and put int queue)
        int m =grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        //m=row ||  n=col
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //first row, first col, last row, last col
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        //STEP-2( after pushing ,check left ,right,top,bottom if any 1 occurs mark it as 1 in vis and push into the queue until queue is empty)
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse all 4 direction
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
                && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        //STEP-3 ( TRAVERSE THE GRID & VIS TO check the remaing 1s)

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;

    } 
};