class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        
        int l = 0 , r = 0;
        int zeros = 0 , maxlen = INT_MIN;
        while (r < arr.size()) {

            if (arr[r] == 0) {
                zeros++;
            }

            while (zeros > 1) {

                l++;
                if (arr[l-1] == 0) zeros--;

            }

            maxlen = max(maxlen , r-l+1);

            // cout << "valid length : " << maxlen << endl;

            r++; 

        }

        return maxlen-1;

    }
};