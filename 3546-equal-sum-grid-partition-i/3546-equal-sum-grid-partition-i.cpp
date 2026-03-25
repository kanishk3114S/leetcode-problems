class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        bool horicut = false , vertical_cut = false;

        vector<long long> rowsum;
        vector<long long> colsum;
        long long size = 0;

        long long prefixsum = 0;
        long long temp = 0;
        for (int i=0; i<m; i++) {
            prefixsum = 0;
            size = rowsum.size()-1;
            for (int j=0; j<n; j++) {

                prefixsum += grid[i][j];

            }
            if (size == -1) {
                rowsum.push_back(prefixsum);
            } else {
                rowsum.push_back(prefixsum + rowsum[size]);
            }
        }        

        prefixsum = 0;
        temp = 0;
        for (int j=0; j<n; j++) {
            prefixsum = 0;
            size = colsum.size()-1;
            for (int i=0; i<m; i++) {

                prefixsum += grid[i][j];

            }
            if (size == -1) {
                colsum.push_back(prefixsum);
            } else {
                colsum.push_back(prefixsum + colsum[size]);
            }
        }

        //for the horizontol cut //
        long long rest = 0;
        for (int i=0; i<m; i++) {

            rest = rowsum[m-1]-rowsum[i];

            if (rowsum[i] == rest) return true;

        }
        for (int i=0; i<n; i++) {

            rest = colsum[n-1]-colsum[i];

            if (colsum[i] == rest) return true;

        }
        return false;
    }
};