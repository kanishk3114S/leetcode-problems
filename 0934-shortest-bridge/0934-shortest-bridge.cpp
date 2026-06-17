class Solution {
    queue<pair<int,int>> q;
public:

    void dfs(vector<vector<int>>&grid , int row , int col , vector<vector<bool>>&vis) {

        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || vis[row][col] || grid[row][col] == 0) return;

        vis[row][col] = true;
        q.push({row , col}); //push the 1st into the queue//

        dfs(grid, row+1 , col ,vis);
        dfs(grid, row , col+1 ,vis);
        dfs(grid, row , col-1 ,vis);
        dfs(grid, row-1 , col ,vis);

    }

    bool gotIsland(int r , int c , vector<vector<int>>&grid , vector<vector<bool>> &vis) {

    if (r > 0 && grid[r-1][c] == 1 && !vis[r-1][c]) {
        return true;
    }
    if (c > 0 && grid[r][c-1] == 1 && !vis[r][c-1]) {
    return true;
    }
    if (r != grid.size()-1 && grid[r+1][c] == 1 && !vis[r+1][c]) {
        return true;
    }
    if (c != grid[0].size()-1 && grid[r][c+1] == 1 && !vis[r][c+1]) {
    return true;
    }   

    return false;

    }


    int shortestBridge(vector<vector<int>>& grid) {
        
        vector<vector<bool>> vis(grid.size() , vector<bool>(grid[0].size() , false));

        bool found = false;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    dfs(grid,i,j,vis);
                    found = true;
                    break;
                }
            }
            if (found) break;
            
        }

        int dist = 0;

        while (!q.empty()) {

            int sz = q.size();

            for (int i=0; i<sz; i++) {

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if (gotIsland(r,c,grid,vis)) return dist;

                if (r > 0 && grid[r-1][c] == 0 && !vis[r-1][c]) {
                    q.push({r-1  , c});
                    vis[r-1][c] = true;
                }
                if (c > 0 && grid[r][c-1] == 0 && !vis[r][c-1]) {
                    q.push({r , c-1});
                    vis[r][c-1]=true;
                }
                if (r != grid.size()-1 && grid[r+1][c] == 0 && !vis[r+1][c]) {
                    q.push({r+1  , c});
                    vis[r+1][c]=true;
                }
                if (c != grid[0].size()-1 && grid[r][c+1] == 0 && !vis[r][c+1]) {
                    q.push({r, c+1});
                    vis[r][c+1]=true;
                }                

            }
            dist++;
        }

        return dist;

        while (!q.empty()) q.pop();

    }
};