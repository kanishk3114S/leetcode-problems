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

        int cnt = 0;
        int idx = 0;
        int reqidx = -1;
        while (idx < arr.size()) {

            int req = n-1-idx;
            if (arr[idx] < req) {
            reqidx = -1;
            for (int i=idx+1; i<n; i++) {
                if (arr[i] >= req) {
                    reqidx = i;
                    break;
                }
            }
                            if (reqidx == -1) return -1;
                while (reqidx > idx) {
                        swap(arr[reqidx] , arr[reqidx-1]);
                        cnt++;
                        reqidx--;
                    }
            }



                    idx++;

        }

        return cnt;



    }
};