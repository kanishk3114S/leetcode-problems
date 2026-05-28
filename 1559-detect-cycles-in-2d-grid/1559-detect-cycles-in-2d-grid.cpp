class Solution {
public:

    bool bfs(vector<vector<char>>& grid  , vector<vector<bool>>&vis , char ch , int row  , int col) {

        queue<pair<pair<int,int> ,pair<int,int>>> q;

        q.push({{row,col} , {-1,-1}});
        vis[row][col] = true;
        
        int pr = 0 , pc = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                if (r != -1 && c != -1) {
                    pr = q.front().second.first;
                    pc = q.front().second.second;
                }
                if (ch == 'b') {
                    cout << r << " " << c <<endl;
                }
                q.pop();

                if (r!=0 && grid[r-1][c] == ch && !(r-1 == pr && c ==pc)) {
                    if (vis[r-1][c]) return true;
                    else {
                        vis[r-1][c] = true;
                        q.push({{r-1 , c} , {r , c}});
                    }
                } 
                if (c!=0 && grid[r][c-1] == ch && !(r == pr && c-1 ==pc)) {
                    if (vis[r][c-1]) return true;
                    else {
                        vis[r][c-1] = true;
                        q.push({{r , c-1}, {r,c}});
                    }
                } 
                if (r!=grid.size()-1 && grid[r+1][c] == ch && !(r+1 == pr && c ==pc)) {
                    if (vis[r+1][c]) return true;
                    else {
                        vis[r+1][c] = true;
                        q.push({{r+1 , c}, {r,c}});
                    }
                } 
                if (c!=grid[0].size()-1 && grid[r][c+1] == ch && !(r == pr && c+1 ==pc)) {
                    if (vis[r][c+1]) return true;
                    else {
                        vis[r][c+1] = true;
                        q.push({{r , c+1}, {r,c}});
                    }
                } 

            }

        }
        return false;

    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (!vis[i][j]) {

                    // cout << "bfs runned for " << i << " " << j;
                    // cout << endl;

                    if (bfs(grid , vis , grid[i][j] , i , j)) return true;
                }

            }
        }
        return false;

    }
};