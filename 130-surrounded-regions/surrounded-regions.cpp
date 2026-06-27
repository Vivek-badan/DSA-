class Solution {
public:

    void dfs(int row,int col,
             vector<vector<int>>&vis,
             vector<vector<char>>&board,
             int delrow[],          // <-- int delrow[] instead of int delrow
             int delcol[]) {        // <-- int delcol[] instead of int delcol

        vis[row][col]=1;

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<4;i++){

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n &&      // <-- n instead of m
               ncol>=0 && ncol<m &&
               !vis[nrow][ncol] &&
               board[nrow][ncol]=='O'){

                dfs(nrow,ncol,vis,board,delrow,delcol);
                // <-- board instead of mat
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();          // <-- Missing
        int m = board[0].size();       // <-- Missing

        vector<vector<int>> vis(n,vector<int>(m,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        // Traverse first and last row
        for(int j=0;j<m;j++){

            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,delrow,delcol);
                // <-- board instead of mat
                // <-- pass both delrow and delcol
            }

            if(!vis[n-1][j] && board[n-1][j]=='O'){
                // <-- [j] instead of [0]

                dfs(n-1,j,vis,board,delrow,delcol);
                // <-- board instead of mat
            }
        }

        // Traverse first and last column
        for(int i=0;i<n;i++){      // <-- use i instead of j

            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,delrow,delcol);
            }

            if(!vis[i][m-1] && board[i][m-1]=='O'){
                // <-- m-1 instead of n-1

                dfs(i,m-1,vis,board,delrow,delcol);
                // <-- i instead of j
            }
        }

        // Convert remaining O to X
        for(int i=0;i<n;i++){      // <-- n instead of m

            for(int j=0;j<m;j++){

                if(!vis[i][j] && board[i][j]=='O'){
                    // <-- board instead of mat
                    // <-- 'O' instead of 'o'

                    board[i][j]='X';
                    // <-- board instead of mat
                }
            }
        }
    }
};