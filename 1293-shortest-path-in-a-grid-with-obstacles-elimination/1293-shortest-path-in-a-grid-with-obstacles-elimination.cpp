class Solution {
public:

    struct D {
        int first;
        int second;
        int third;
        int fourth;

        bool operator<(const D& other) const {
            return first > other.first;   // min heap by distance
        }
    };

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m, vector<int>(k + 1, INT_MAX)));

        //now dist[r][c][x] gives us the at most x stops for row col and state x//
        // dist , obs , row , col //

        priority_queue<D> pq;

        if (grid[0][0] == 1) {
            pq.push({0 , 1 , 0 , 0});
            dist[0][0][1] = 0;
        } else {
            pq.push({0 , 0 , 0 , 0});
            dist[0][0][0] = 0;
        }

        while (!pq.empty()) {

            int d = pq.top().first;
            int currK = pq.top().second;
            int row = pq.top().third;
            int col = pq.top().fourth;
            pq.pop();

            if (row == n-1 && col == m-1) return d;

            if (row > 0) {
                if (grid[row - 1][col] == 1) {
                    if (currK + 1 <= k) {
                        if (d + 1 < dist[row - 1][col][currK + 1]) {
                            pq.push({d + 1, currK + 1, row - 1, col});
                            dist[row - 1][col][currK + 1] = d + 1;
                        }
                    }
                } else {
                    if (d + 1 < dist[row - 1][col][currK]) {
                        pq.push({d + 1, currK, row - 1, col});
                        dist[row - 1][col][currK] = d + 1;
                    }
                }
            }

            if (col < m - 1) {
                if (grid[row][col + 1] == 1) {
                    if (currK + 1 <= k) {
                        if (d + 1 < dist[row][col + 1][currK + 1]) {
                            pq.push({d + 1, currK + 1, row, col + 1});
                            dist[row][col + 1][currK + 1] = d + 1;
                        }
                    }
                } else {
                    if (d + 1 < dist[row][col + 1][currK]) {
                        pq.push({d + 1, currK, row, col + 1});
                        dist[row][col + 1][currK] = d + 1;
                    }
                }
            }

            if (col > 0) {
                if (grid[row][col - 1] == 1) {
                    if (currK+1 <= k) {
                    if (d + 1 < dist[row][col - 1][currK + 1]) {
                        pq.push({d + 1, currK + 1, row, col - 1});
                        dist[row][col - 1][currK + 1] = d + 1;
                    }
                    }
                } else {
                    if (d + 1 < dist[row][col - 1][currK]) {
                        pq.push({d + 1, currK, row, col - 1});
                        dist[row][col - 1][currK] = d + 1;
                    }
                }
            }

            if (row < n - 1) {
                if (grid[row + 1][col] == 1) {
                    if (currK + 1 <= k) {
                        if (d + 1 < dist[row + 1][col][currK + 1]) {
                            pq.push({d + 1, currK + 1, row + 1, col});
                            dist[row + 1][col][currK + 1] = d + 1;
                        }
                    }
                } else {
                    if (d + 1 < dist[row + 1][col][currK]) {
                        pq.push({d + 1, currK, row + 1, col});
                        dist[row + 1][col][currK] = d + 1;
                    }
                }
            }        
        }

        return -1;
    }
};