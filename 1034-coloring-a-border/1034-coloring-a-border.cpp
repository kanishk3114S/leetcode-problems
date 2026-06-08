class Solution {
public:

    bool isvalid(int row , int col , int n  , int m) {

        if (row == 0 || col == 0 || row == n-1 || col == m-1) return true;

        return false;

    }

    bool second(int r , int c , int n , int m , vector<vector<int>>& grid , int color) {

                if (r > 0 && grid[r-1][c] != color) {
                    return true;
                }
                if (c > 0 && grid[r][c-1] != color) {
                return true;
                }
                if (r != n-1 && grid[r+1][c] != color) {
                    return true;
                }
                if (c != m-1 && grid[r][c+1] != color) {
                return true;
                }

                return false;

    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        //single source bfs problem//

        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> original = grid;
        //dist...row...col//

        int srcclr = grid[row][col];
        if (isvalid(row,col,n,m) || second(row,col,n,m,grid,srcclr)) {
            grid[row][col] = color;
        }
        vis[row][col] = true;
        q.push({row , col});

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if (r > 0 && original[r-1][c] == srcclr && !vis[r-1][c]) {
                    if (isvalid(r-1,c,n,m) || second(r-1,c,n,m,original,srcclr)) {
                        grid[r-1][c] = color;
                    }
                    vis[r-1][c] = true;
                    q.push({r-1 , c});
                }
                if (c > 0 && original[r][c-1] == srcclr && !vis[r][c-1]) {
                    if (isvalid(r,c-1,n,m) || second(r,c-1,n,m,original,srcclr)) {
                        grid[r][c-1] = color;
                    }
                    vis[r][c-1] = true;
                    q.push({r, c-1});
                }
                if (r != n-1 && original[r+1][c] == srcclr && !vis[r+1][c]) {
                    if (isvalid(r+1,c,n,m) || second(r+1,c,n,m,original,srcclr)) {
                        grid[r+1][c] = color;
                    }
                    vis[r+1][c] = true;
                    q.push({r+1 , c});
                }
                if (c != m-1 && original[r][c+1] == srcclr && !vis[r][c+1]) {
                    if (isvalid(r,c+1,n,m) || second(r,c+1,n,m,original,srcclr)) {
                        grid[r][c+1] = color;
                    }
                    vis[r][c+1] = true;
                    q.push({r, c+1});
                }
            }


        }

        return grid;

    }
};