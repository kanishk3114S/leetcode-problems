class Solution {
public:

    void dfs(vector<vector<char>>& board , int row , int col , vector<vector<bool>>&vis) {

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || vis[row][col] || board[row][col] == '.') return;

        if (board[row][col] == 'X') {
            vis[row][col] = true;
        }

        dfs(board , row+1 , col , vis);
        dfs(board , row-1,col , vis);
        dfs(board , row , col+1 , vis);
        dfs(board , row , col-1, vis);

    }

    int countBattleships(vector<vector<char>>& board) {
        
        int cnt =0;
        vector<vector<bool>> vis(board.size() , vector<bool>(board[0].size() , false));

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {

                if (board[i][j] == 'X' && !vis[i][j]) {
                    cnt++;
                    dfs(board , i , j , vis);
                }

            }
        }


        return cnt;

    }
};