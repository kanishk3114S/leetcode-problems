class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,pair<int,int>>> q;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (grid[i][j] == 0) {

                    q.push({0 , {i , j}});
                    vis[i][j] = true;

                }

            }
        }

        while (!q.empty()) {

            int size = q.size();


            for (int i=0; i<size; i++) {

                int dist = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();

                if (row > 0 && grid[row-1][col] == 1 && !vis[row-1][col]) {
                    grid[row-1][col] = dist+1;
                    vis[row-1][col] = true;
                    q.push({dist+1 , {row-1 , col}});
                }

                if (row != n-1 && grid[row+1][col] == 1 && !vis[row+1][col]) {
                    grid[row+1][col] = dist+1;
                    vis[row+1][col] = true;
                    q.push({dist+1 , {row+1,col}});
                }

                if(col > 0 && grid[row][col-1] == 1 && !vis[row][col-1]) {
                    grid[row][col-1] = dist+1;
                    vis[row][col-1] = true;
                    q.push({dist+1 , {row , col-1}});
                }

                if (col != m-1 && grid[row][col+1] == 1 && !vis[row][col+1]) {
                    grid[row][col+1] = dist+1;
                    vis[row][col+1] = true;
                    q.push({dist+1 , {row , col+1}});
                }

            }

        }

        return grid;

    }
};