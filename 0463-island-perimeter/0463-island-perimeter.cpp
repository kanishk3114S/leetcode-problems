class Solution {
public:

    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
            int contri = 0;

            if (grid[i][j] == 1) {
                if (i > 0 && grid[i-1][j] == 0) { //left mein water//
                    contri++; 
                } else if (i == 0) {
                    contri++;
                }

                if (j > 0 && grid[i][j-1] == 0) { //left mein water//
                    contri++; 
                } else if (j == 0) {
                    contri++;
                }

                if (i != n-1 && grid[i+1][j] == 0) contri++;
                else if (i == n-1) contri++;

                if (j != m-1 && grid[i][j+1] == 0) contri++;
                else if (j == m-1) contri++;

                ans += contri;
            }


            }
        }

        return ans;

    }
};