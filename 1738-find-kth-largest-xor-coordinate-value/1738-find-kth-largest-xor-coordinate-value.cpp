class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mat, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> xr(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int up   = (i > 0) ? xr[i - 1][j] : 0;
                int left = (j > 0) ? xr[i][j - 1] : 0;
                int diag = (i > 0 && j > 0) ? xr[i - 1][j - 1] : 0;

                xr[i][j] = mat[i][j] ^ up ^ left ^ diag;

                pq.push(xr[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};