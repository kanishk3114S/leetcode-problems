class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //MULTI SOURCE BFS//

        queue<vector<int>> q;

        int n=grid.size() , m = grid[0].size();

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

            
            if (grid[i][j] == 2) {

                q.push({i,j});
            
            }
        }

        }

        int t=0;
        while (!q.empty()) {

            int size = q.size();
            // cout << size << " ";
            bool rotted = false;
            for (int i=0; i<size; i++) {

                int sr = q.front()[0];
                int sc = q.front()[1];
                q.pop();

                if (sc != 0 && grid[sr][sc-1] == 1) {
                    grid[sr][sc-1]=2;
                    rotted = true;
                    q.push({sr , sc-1});
                }
                if (sr != 0 && grid[sr-1][sc] == 1) {
                    grid[sr-1][sc]=2;
                    rotted = true;
                    q.push({sr-1 , sc});
                }
                if (sr != n-1 && grid[sr+1][sc] == 1){
                    grid[sr+1][sc] = 2;
                    rotted = true;
                    q.push({sr+1 , sc});
                }
                if (sc != m-1 && grid[sr][sc+1] == 1){
                    grid[sr][sc+1] = 2;
                    rotted = true;
                    q.push({sr , sc+1});

                }

            }

            if (rotted) t++;

        }

        // cout << t << " ";

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return t;
    }
};