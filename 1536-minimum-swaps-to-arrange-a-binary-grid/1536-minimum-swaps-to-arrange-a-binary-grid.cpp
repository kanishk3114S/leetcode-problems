class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr(n , 0);
        for (int i=0; i<n; i++) {
            arr[i] = n;
            for (int j=n-1; j>-1; j--) {
                //iterating over every row//

                if (grid[i][j] == 1) {
                    arr[i] = n-1-j;
                    break;

                }
            }
        }
        

        //we need the typical bubble sort//
        //that solution exists//

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n-1-i;
            int j = i;

            while (j < n && arr[j] < need) j++;
            if (j == n) return -1;

            while (j > i) {
                swap(arr[j], arr[j-1]);
                swaps++;
                j--;
            }
        }
        return swaps;

    }
};