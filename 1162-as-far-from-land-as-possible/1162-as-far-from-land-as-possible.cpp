class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int dist = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;

        for (int i=0; i<n; i++) {

            for (int j=0; j<m; j++) {

                if (grid[i][j] == 1) {
                    q.push({i,j});
                }
            }

        }

        while (!q.empty()) {

            int size = q.size();

            bool covered = false;

            for (int i=0; i<size; i++) {

                int row = q.front().first;
                int col = q.front().second;

                q.pop();


                if (row > 0 && grid[row-1][col] == 0 && !vis[row-1][col]) {
                    vis[row-1][col] = true;
                    q.push({row-1 , col});
                    covered = true;
                }
                if (col > 0 && grid[row][col-1] == 0 && !vis[row][col-1]) {
                    vis[row][col-1] = true;
                    q.push({row , col-1});
                    covered = true;
                }
                if (row != n-1 && grid[row+1][col] == 0 && !vis[row+1][col]) {
                    vis[row+1][col] = true;
                    q.push({row+1, col});
                    covered = true;
                }
                if (col != m-1 && grid[row][col+1] == 0 && !vis[row][col+1]) {
                    vis[row][col+1] = true;
                    q.push({row , col+1});
                    covered = true;
                }


            }

            if (covered) dist++;


        }

        return dist==0?-1:dist;

    }
};