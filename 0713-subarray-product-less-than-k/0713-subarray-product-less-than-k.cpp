class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        
        long long prod = 1;
        int cnt = 0;

        int l = 0 , r = 0;

        while (r < arr.size()) {

            prod *= arr[r];

            while (l<r && prod >= k) {
                prod /= arr[l];
                l++;
            }

            if (prod < k)  {

                cnt += r-l+1;

            }

            r++;

        }

        return cnt;

    }
};