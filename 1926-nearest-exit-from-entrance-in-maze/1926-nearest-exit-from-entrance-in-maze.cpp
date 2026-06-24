class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        
        set<pair<int,int>> exit;
        int n = maze.size();
        int m = maze[0].size();

        for (int i=0; i<m; i++) {

            if (maze[0][i] == '.') {
                exit.insert({0 , i});
            }
            if (maze[n-1][i] == '.') {
                exit.insert({n-1 , i});
            }
        }

        for (int j=0; j<n; j++) {

            if (maze[j][0] == '.') {
                exit.insert({j , 0});
            }

            if (maze[j][m-1] == '.') {
                exit.insert({j , m-1});
            }

        }

        queue<pair<int,int>> q;

        q.push({ent[0] , ent[1]});
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        
        if (exit.count({ent[0] , ent[1]})) {
            exit.erase({ent[0] , ent[1]});
        }

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            for (int i=0; i<sz; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (exit.count({row,col})) {
                    return moves;
                }

                if (row > 0 && maze[row-1][col] == '.' && !vis[row-1][col]) {

                    q.push({row-1,col});
                    vis[row-1][col] = true;

                }
                if (col > 0 && maze[row][col-1] == '.' && !vis[row][col-1]) {

                    q.push({row,col-1});
                    vis[row][col-1] = true;

                }
                if (row < n-1 && maze[row+1][col] == '.' && !vis[row+1][col]) {

                    q.push({row+1,col});
                    vis[row+1][col] = true;

                }
                if (col < m-1 && maze[row][col+1] == '.' && !vis[row][col+1]) {

                    q.push({row,col+1});
                    vis[row][col+1] = true;

                }
            }
            moves++;
        }

        return -1;

    }
};