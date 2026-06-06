class Solution {
public:
    int valueAfterKSeconds(int n, int k) {

        const long long mod = 1e9+7;
        
        vector<int> arr(n , 1); // current state//
        vector<int> next(n , 0); //next state//

        for (int i=0; i<k; i++) {
            long long sum = 0;
        for (int i=0; i<arr.size(); i++) {

            sum = (sum + arr[i])%mod;
            next[i] = sum;

        }
        arr = next;
        }

        return next[n-1];

    }
};