class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result(n,vector<int>(m , 0));

        const long long MOD = 12345;
        int idx = 0 , prev = 0 , next = 0;

        vector<long long> arr;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        vector<long long> prefix;
        vector<long long> suffix;

        long long prod1 = 1 , prod2 = 1;

        for (int i=0; i<arr.size(); i++) {

            prod1 = (prod1*arr[i])%MOD;
            prefix.push_back(prod1);

        }
        for (int i=arr.size()-1; i>-1; i--) {

            prod2 = (prod2*arr[i])%MOD;
            suffix.push_back(prod2);

        }
        reverse(suffix.begin() , suffix.end());

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                idx = (i*m)+j;
                prev = idx-1;
                next = idx+1;

                if (prev == -1) {
                    result[i][j] = (suffix[next]%MOD);
                }else if (next == arr.size()) {
                    result[i][j] = (prefix[prev]%MOD);
                } else{
                result[i][j] = (prefix[prev]*suffix[next])%MOD;
                }
            }
        }

        return result;


    }
};