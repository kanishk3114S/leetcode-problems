class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        
        int l = 0 , r = k-1;
        double sum = 0 , average = 0;
        for (int i=l; i<=r; i++) {
            sum += (double)arr[i];
        }

        double maxsum = sum;

        while (r < arr.size()) {

            sum-=arr[l];
            l++;
            r++;
            if (r == arr.size()) break;
            sum += arr[r];
            maxsum = max(sum , maxsum);

        }

        average = maxsum/k;

        return average;

    }
};