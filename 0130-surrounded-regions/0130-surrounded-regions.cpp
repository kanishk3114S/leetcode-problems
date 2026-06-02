class Solution {
public:

    void dfs(vector<vector<char>>& board , vector<vector<bool>>& vis , int n , int m , int row , int col) {

        if (row < 0 || col < 0 || row >=n || col>=m || vis[row][col] || board[row][col] == 'X') return;

        vis[row][col] = true;

        dfs(board , vis , n , m , row+1 ,col);
        dfs(board , vis , n , m , row-1 ,col);
        dfs(board , vis , n , m , row ,col-1);
        dfs(board , vis , n , m , row ,col+1);

    }

    void solve(vector<vector<char>>& board) {
        
        //for top and bottom check if zero is there//

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));

        for (int i=0; i<m; i++) {

            if (board[0][i] == 'O') {dfs(board , vis , n , m , 0 , i);}
            if (board[n-1][i] == 'O') {dfs(board , vis , n , m , n-1 , i);}

        }

        for (int i=0; i<n; i++) {

            if (board[i][0] == 'O')  {dfs(board , vis , n , m , i, 0);}
            if (board[i][m-1] == 'O') {dfs(board , vis , n , m , i, m-1);}

        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (board[i][j] == 'O' && !vis[i][j]) {


                    board[i][j] ='X';
                }
                    // if (i==j && i==1) cout << vis[i][j];

            }
        }



    }
};