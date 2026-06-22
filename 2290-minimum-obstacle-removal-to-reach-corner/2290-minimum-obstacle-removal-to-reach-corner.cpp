class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dist(n , vector<int>(m , INT_MAX));
        
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        
        if (grid[0][0] == 1) {
            pq.push({1 , {0,0}});
            dist[0][0] = 1;
        } else {
            pq.push({0 , {0,0}});
            dist[0][0] = 0;
        }

        while (!pq.empty()) {

            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n-1 && col == m-1) return d;

            if (row > 0) {
                if (grid[row-1][col] == 1) {
                    if (d+1 < dist[row-1][col]) {
                        pq.push({d+1 , {row-1,col}});
                        dist[row-1][col] = d+1;
                    }
                } else {
                    if (d < dist[row-1][col]) {
                        pq.push({d,{row-1,col}});
                        dist[row-1][col] = d;
                    }
                }
            }
            if (col < m-1) {
                if (grid[row][col+1] == 1) {
                    if (d+1 < dist[row][col+1]) {
                        pq.push({d+1 , {row,col+1}});
                        dist[row][col+1] = d+1;
                    }
                } else {
                    if (d < dist[row][col+1]) {
                        pq.push({d,{row,col+1}});
                        dist[row][col+1] = d;
                    }
                }
            }
            if (col > 0) {
                if (grid[row][col-1] == 1) {
                    if (d+1 < dist[row][col-1]) {
                        pq.push({d+1 , {row,col-1}});
                        dist[row][col-1] = d+1;
                    }
                } else {
                    if (d < dist[row][col-1]) {
                        pq.push({d,{row,col-1}});
                        dist[row][col-1] = d;
                    }
                }
            }
            if (row < n-1) {
                if (grid[row+1][col] == 1) {
                    if (d+1 < dist[row+1][col]) {
                        pq.push({d+1 , {row+1,col}});
                        dist[row+1][col] = d+1;
                    }
                } else {
                    if (d < dist[row+1][col]) {
                        pq.push({d,{row+1,col}});
                        dist[row+1][col] = d;
                    }
                }
            }
        }

        return 0;

    }
};