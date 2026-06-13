class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int i=0 , j = sqrt(c);

        while (i <= j) {

            long long sum = 1LL*i*i + 1LL*j*j;
            // cout << sum << " " << i << " " << j <<endl;
            if (sum == c) return true;
            else if (sum > c) j--;
            else i++;
        }

        return false;

    }
};