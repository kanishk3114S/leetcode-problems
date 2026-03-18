class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pref(m , vector<int>(n));

        int temp = 0;
        int prefsum = 0;
        int prevrow = -1;

        for (int i=0; i<m; i++) {
            prefsum = 0;
            for (int j = 0; j<n; j++) {
                prevrow = i-1;
                if (prevrow == -1) {
                    temp = 0;
                } else {
                temp = pref[prevrow][j];
                }
                prefsum += grid[i][j];

                pref[i][j] = (prefsum+temp);
            }
        }

        //prefgrid will contain all  the submatrices containing the first top left element...//

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {

                if (pref[i][j] <= k) {
                    ans++;
                }

            }
        }

        return ans;


    }
};