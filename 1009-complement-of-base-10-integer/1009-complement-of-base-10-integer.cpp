class Solution {
public:
    int bitwiseComplement(int n) {

        if (n==0) {
            return 1;
        }

        int no_of_bits = 1+log2(n);
        int limit = (1<<(no_of_bits))-1;

        int ans = 0;

        ans = n^limit;
        return ans;

    }
};