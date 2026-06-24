class Solution {
public:

    void dfs(vector<vector<int>>& land , vector<vector<bool>>& vis , int row , int col , pair<int,int>&minp , pair<int,int>&maxp) {

        if (row<0 || col<0 || row > land.size()-1 || col > land[0].size()-1 || vis[row][col] || land[row][col] == 0) return;

        minp.first = min(row , minp.first);
        minp.second = min(col , minp.second);
        maxp.first = max(row , maxp.first);
        maxp.second = max(col , maxp.second);

        vis[row][col] = true;

        dfs(land,vis,row-1,col,minp,maxp);
        dfs(land,vis,row,col+1,minp,maxp);
        dfs(land,vis,row+1,col,minp,maxp);
        dfs(land,vis,row,col-1,minp,maxp);

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        pair<int,int> minp , maxp;
        int n = land.size() , m = land[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for (int i=0; i<n; i++) {

            for (int j=0; j<m; j++) {

                if (!vis[i][j] && land[i][j] == 1) {

                    minp = {INT_MAX,INT_MAX};
                    maxp = {INT_MIN , INT_MIN};

                    dfs(land , vis , i , j , minp , maxp);

                    ans.push_back({minp.first , minp.second , maxp.first , maxp.second});

                }

            }

        }
        return ans;

    }
};