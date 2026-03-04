class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>onerow(n,0);
        vector<int>onecol(m,0);
        vector<int>zerorow(n,0);
        vector<int>zerocol(m,0);

        vector<vector<int>> result(n , vector<int>(m , 0));

        for (int i=0; i<n; i++) {

            for (int j=0; j<m; j++) {

                if(grid[i][j] == 1) {
                    onerow[i]++;
                    onecol[j]++;
                }

            }

            zerorow[i] = m-onerow[i];

        }

        for (int i=0; i<onecol.size(); i++) {

            zerocol[i] = n-onecol[i];

        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                result[i][j] = onerow[i]+onecol[j]-zerorow[i]-zerocol[j];

            }
        }

        return result;



    }
};