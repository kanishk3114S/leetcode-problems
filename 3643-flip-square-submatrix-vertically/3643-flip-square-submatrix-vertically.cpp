class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        

    int m = grid.size();
    int n = grid[0].size();
    int lastrow = x+k-1;
    for (int i=x; i<x+k; i++) {
        if (lastrow < i) return grid;
        for (int j=y; j<y+k; j++) {

            swap(grid[i][j] , grid[lastrow][j]);

        }
        lastrow--;

    }

    return grid;


    }
};