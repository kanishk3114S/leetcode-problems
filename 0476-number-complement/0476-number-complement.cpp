class Solution {
public:
    int findComplement(int n ) {
        if (n==0) {
            return 1;
        }

        long long no_of_bits = 1+log2(n);
        // cout << no_of_bits << endl;
        long long limit = 0;
        if (no_of_bits == 31) {
            limit = INT_MAX;
        } else {
        limit = (1<<(no_of_bits))-1;

        }

        long long ans = 0;

        ans = n^limit;
        return ans;
    }
};