class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> col(n);
        vector<int> row(m);
        for (int i=0; i<m; i++) {
            int minel = INT_MAX;
            for (int j=0; j<n; j++) {
                
                if (matrix[i][j] > col[j]) {
                    col[j] = matrix[i][j];
                }
                minel = min(minel , matrix[i][j]);

            }

            row[i] = minel;

        }

        vector<int> ans;

        for (int i=0; i<row.size(); i++) {
            for (int j=0; j<col.size(); j++) {

                if (col[j] == row[i]) ans.push_back(col[j]);

            }
        }

        return ans;

    }
};