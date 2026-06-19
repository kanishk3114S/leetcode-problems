class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<vector<int>> dist(grid.size() , vector<int>(grid[0].size() , INT_MAX));

        pq.push({0 , {0,0}});
        dist[0][0] = 0;

        //r-1,c-1,r+1,c+1 --> 4,2,1,3//

        while (!pq.empty()) {

            int cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            int newcost = 0;

            if (row == grid.size()-1 && col == grid[0].size()-1) return cost;

            if (row > 0) {

                if (grid[row][col] == 4) {
                    newcost = cost;
                } else {
                    newcost = cost+1;
                }

                if (newcost < dist[row-1][col]) {
                    dist[row-1][col] = newcost;
                    pq.push({newcost , {row-1 , col}});
                }

            }
            if (col > 0) {

                if (grid[row][col] == 2) {
                    newcost = cost;
                } else {
                    newcost = cost+1;
                }

                if (newcost < dist[row][col-1]) {
                    dist[row][col-1] = newcost;
                    pq.push({newcost , {row , col-1}});
                }

            }
            if (row != grid.size()-1) {

                if (grid[row][col] == 3) {
                    newcost = cost;
                } else {
                    newcost = cost+1;
                }

                if (newcost < dist[row+1][col]) {
                    dist[row+1][col] = newcost;
                    pq.push({newcost , {row+1 , col}});
                }

            }
            if (col != grid[0].size()-1) {

                if (grid[row][col] == 1) {
                    newcost = cost;
                } else {
                    newcost = cost+1;
                }

                if (newcost < dist[row][col+1]) {
                    dist[row][col+1] = newcost;
                    pq.push({newcost , {row , col+1}});
                }

            }

        }

        return -1;

    }
};