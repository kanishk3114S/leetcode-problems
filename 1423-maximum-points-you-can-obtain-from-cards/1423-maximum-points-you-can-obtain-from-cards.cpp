class Solution {
public:
    int maxScore(vector<int>& arr, int psuedok) {
        //maximize the ring sum of size k by making the window of the size of n-k//

        int k = arr.size() - psuedok;
        int l = 0 , r = k-1;
        int sum = 0;
        for (int i=l; i<=r; i++) { 
            sum += arr[i];
        }

        int total = 0;

        for (int val:arr) {
            total+=val;
        }

        // cout << " total : " << total << endl;

        int minsum = sum;
        // cout << "minsum : " << minsum << endl;


        while (r < arr.size()) {
            sum -= arr[l];
            l++;
            r++;
            if (r==arr.size()) break;
            sum += arr[r];
            minsum = min(minsum , sum);
            // cout << "minsum : " << minsum << endl;
        }



        int ans =  total-minsum;

        return ans;


    }
};