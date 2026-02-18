class Solution {
public:
    bool hasAlternatingBits(int n) {

        // O(1) TIME COMPLEXITY //

        long long a = 0;

        a = (n ^ (n>>1));

        if ((a & (a+1)) == 0) return true;
        

        return false;

    }
};