class Solution {
public:

    void dfs(vector<vector<int>>& board , vector<vector<bool>>& vis , int n , int m , int row , int col) {

        if (row < 0 || col < 0 || row >=n || col>=m || vis[row][col] || board[row][col] == 0) return;

        vis[row][col] = true;

        dfs(board , vis , n , m , row+1 ,col);
        dfs(board , vis , n , m , row-1 ,col);
        dfs(board , vis , n , m , row ,col-1);
        dfs(board , vis , n , m , row ,col+1);

    }

    int numEnclaves(vector<vector<int>>& board) {
        
        //for top and bottom check if zero is there//

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));

        for (int i=0; i<m; i++) {

            if (board[0][i] == 1) {dfs(board , vis , n , m , 0 , i);}
            if (board[n-1][i] == 1) {dfs(board , vis , n , m , n-1 , i);}

        }

        for (int i=0; i<n; i++) {

            if (board[i][0] == 1)  {dfs(board , vis , n , m , i, 0);}
            if (board[i][m-1] == 1) {dfs(board , vis , n , m , i, m-1);}

        }

        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (board[i][j] == 1 && !vis[i][j]) {
                    cnt++;
                }
                    // if (i==j && i==1) cout << vis[i][j];

            }
        }

        return cnt;

    }
};