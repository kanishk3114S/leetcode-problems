class Solution {
public:
    int arrangeCoins(int n) {
        /*
        
        n(n+1)/2 == total elements

        find the n;;;;;
        O(1);
        
        */

        long long a = 0 , b = 0;

        a = (-1 + sqrt(1 + (long long)8*n))/2;
        b = (-1 - sqrt(1 + (long long)8*n))/2;

        if (a < 0) return b;
        else return a;


        return 0;


    }
};