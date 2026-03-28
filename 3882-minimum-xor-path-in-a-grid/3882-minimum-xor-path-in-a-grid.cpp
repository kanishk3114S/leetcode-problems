class Solution {
public:

    void helper(vector<vector<int>>&grid , int row , int col , int XOR ,
                vector<vector<unordered_set<int>>>& vis , int& ans) {

        int m = grid.size();
        int n = grid[0].size();
        
        if (row < 0 || col < 0 || row >=m || col >=n) return;

        XOR ^= grid[row][col];

        if (vis[row][col].count(XOR)) return;
        vis[row][col].insert(XOR);

        if (row == m-1 && col == n-1) {
            ans = min(XOR , ans);
            return;
        }

        helper(grid , row+1 , col , XOR , vis , ans);
        helper(grid , row , col+1 , XOR , vis , ans);
    }
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<unordered_set<int>>> vis(m , vector<unordered_set<int>>(n));

        int ans = INT_MAX;
        helper(grid , 0 , 0 , 0 , vis , ans);
        return ans;
    }
};