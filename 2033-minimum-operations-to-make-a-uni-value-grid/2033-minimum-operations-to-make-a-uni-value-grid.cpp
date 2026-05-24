class Solution {
public:
    double median(vector<int>& arr) {
        int n = arr.size();

        if (n % 2)
            return arr[n / 2];

        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> arr;

        int rem = grid[0][0]%x;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {

                if (grid[i][j]%x != rem) return -1;

                arr.push_back(grid[i][j]);

            }

        }

        sort(arr.begin() , arr.end());

        int a = median(arr);
        int ans= 0;
        for (int i=0; i<arr.size(); i++) {

             ans += abs(a-arr[i]);

        }

        return ans/x;

    }
};