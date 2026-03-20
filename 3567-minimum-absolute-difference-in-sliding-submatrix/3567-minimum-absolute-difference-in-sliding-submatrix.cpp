class Solution {
public:

    int calc(vector<vector<int>>&grid , int k , int st , int end) {
        vector<int> vec;
        int ans = 0;
        unordered_set<int> s;
        for (int i=st; i<st+k; i++) {
            for (int j=end; j<end+k; j++) {
                
                if (s.find(grid[i][j]) == s.end()) s.insert(grid[i][j]);
                
            }
        }

        //now set s has all the distinct values//
        int mindiff = INT_MAX;
        int diff = INT_MAX;
        if (s.size() == 1) return 0;
        else {
            for (auto it:s) {
                vec.push_back(it);
            }

            for (int i=0; i<vec.size()-1; i++) {
                for (int j=i+1; j<vec.size(); j++) {

                    diff = abs(vec[i] - vec[j]);
                    mindiff = min(diff , mindiff);

                }
            }
        }
        // cout << mindiff << endl;
        return mindiff;

    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m-k+1 , vector<int>(n-k+1));

        for (int i=0; i<m-k+1; i++) {
            for (int j=0; j<n-k+1; j++) {
                int val = calc(grid,k,i,j);
                result[i][j] = val;
            }
        }
        return result;
    }
};