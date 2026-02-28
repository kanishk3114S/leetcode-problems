class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1000000007;
        int totalbits = 0;
        long long power = 1;
        long long ans = 0;
        for (int i=n; i>=1; i--) {

            totalbits = 1+log2(i);
            for (int j=0; j<totalbits; j++) {

                ans = (ans + (power * ((i >> j) & 1))) % MOD;
                // cout << ans << " ";
                power = (power*2)%MOD;

            }

        }

        return ans;
       
    }
};