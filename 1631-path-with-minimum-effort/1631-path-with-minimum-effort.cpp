class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<vector<int>> dist(grid.size() , vector<int>(grid[0].size() , INT_MAX));

        pq.push({0 , {0,0}});
        dist[0][0] = 0;

        while (!pq.empty()) {

            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == grid.size()-1 && col == grid[0].size()-1) return diff;

            if (row > 0) {

                int d = grid[row-1][col];
                int new_diff = abs(d-grid[row][col]);
                int effort = max(diff , new_diff);

                if (effort < dist[row-1][col]) {
                    dist[row-1][col] = effort;
                    pq.push({effort , {row-1 , col}});
                } 

            }
            if (col > 0) {

                int d = grid[row][col-1];
                int new_diff = abs(d-grid[row][col]);
                int effort = max(diff , new_diff);

                if (effort < dist[row][col-1]) {
                    dist[row][col-1] = effort;
                    pq.push({effort , {row , col-1}});
                } 

            }
            if (row != grid.size()-1) {

                int d = grid[row+1][col];
                int new_diff = abs(d-grid[row][col]);
                int effort = max(diff , new_diff);

                if (effort < dist[row+1][col]) {
                    dist[row+1][col] = effort;
                    pq.push({effort , {row+1 , col}});
                } 

            }
            if (col != grid[0].size()-1) {

                int d = grid[row][col+1];
                int new_diff = abs(d-grid[row][col]);
                int effort = max(diff , new_diff);

                if (effort < dist[row][col+1]) {
                    dist[row][col+1] = effort;
                    pq.push({effort , {row, col+1}});
                } 

            }


        }

        return 0;


    }
};