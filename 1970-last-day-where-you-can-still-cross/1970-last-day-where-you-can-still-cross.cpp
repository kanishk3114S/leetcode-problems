class Solution {
public:

    bool check(vector<vector<int>>&grid , vector<vector<bool>>&vis , int row , int col) {

        if (row < 0 || col < 0 || row > grid.size()-1 || col > grid[0].size()-1 || vis[row][col] || grid[row][col] == 1) return false;

        vis[row][col] = true;
        if (row == grid.size()-1) return true;

        if (check(grid,vis,row-1,col)) return true;
        if (check(grid,vis,row,col-1)) return true;
        if (check(grid,vis,row,col+1)) return true;
        if (check(grid,vis,row+1,col)) return true;

        return false;

    }

    int latestDayToCross(int n , int m , vector<vector<int>>& cells) {
        //binary search on answers//

        int l = 0 , r = n*m-1;

        int ans = n*m;

        while (l <= r) {

            int mid = l-(l-r)/2;
            vector<vector<int>> grid(n , vector<int>(m , 0));
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            
            for (int i=0; i<=mid; i++) {

                int row = cells[i][0]-1;
                int col = cells[i][1]-1;

                grid[row][col] = 1;

            }

            bool found = false;

            for (int i=0; i<m; i++) {

                if (check(grid , vis , 0 , i)) {
                    found = true;
                    ans = mid;
                    l = mid+1;
                }

            }

            if (!found) {

                r = mid-1;

            }
        }

        return ans+1;

    }
};