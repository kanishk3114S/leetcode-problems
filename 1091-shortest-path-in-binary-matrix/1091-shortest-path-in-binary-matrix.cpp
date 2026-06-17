class Solution {
public:

    bool isvalid(int r , int c , int n , vector<vector<int>>&grid) {

        if (r < 0 || c < 0 || r >=n || c >= n || grid[r][c] == 1) return false;

        return true;

    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n , vector<bool>(n , false));
        if (grid[0][0] == 0) {
            q.push({0,0});
        }
        vis[0][0] = true;

        int dist = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row == n-1 && col == n-1) return dist;

                for (int i=-1; i<2; i++) {

                    for (int j=-1; j<2; j++) {

                        if (isvalid(row+i , col+j , n , grid) && !vis[row+i][col+j]) {

                            q.push({row+i , col+j});
                            vis[row+i][col+j] = true;

                        }

                    }

                }

            }
            dist++;

        }

        return -1;



    }
};