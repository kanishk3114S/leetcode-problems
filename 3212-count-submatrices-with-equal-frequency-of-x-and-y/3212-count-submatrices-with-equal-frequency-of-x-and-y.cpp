class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int,int>>> vec(m , vector<pair<int,int>>(n));
        int temp1 = -1 , temp2 = -1 , prev = 0;
        vector<int> hash(2 , 0);
        int ans = 0;
        for (int i=0; i<m; i++) {
            hash[0] = 0;
            hash[1] = 0;
            prev = i-1;
            // cout << "prev is : "<< prev << endl;
            for (int j=0; j<n; j++) {

                if (prev == -1) {
                    temp1 = 0;
                    temp2 = 0;
                } else {
                    temp1 = vec[prev][j].first;
                    temp2 = vec[prev][j].second;
                }

                if (grid[i][j] == 'X') hash[0]++;
                else if (grid[i][j] == 'Y') hash[1]++;

                vec[i][j] = {hash[0] + temp1 , hash[1]+temp2};
                // cout << vec[i][j].first<< " "<<vec[i][j].second<<endl;
                if (vec[i][j].first > 0 && vec[i][j].first == vec[i][j].second) {
                    ans++;
                }
            }
        }

        return ans;

    }
};