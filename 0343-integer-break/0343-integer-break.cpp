class Solution {
public:
    int integerBreak(int n) {
        //BREAKING n into the k positive integers where k>=2//
        //OPTIMAL --> do 3 integer breaks//

        if (n==1 || n==2) return 1;
        if (n==3) return 2;

        long long ans = 1;

        while (n > 4) {
            ans*=3;
            n-=3;
        }

        ans*=n;

        return (int)ans;

    }
};