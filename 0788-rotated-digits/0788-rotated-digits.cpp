class Solution {
public:

    bool isgood(int x) {

        int digit = 0;
        bool validdigit = 0;
        while (x > 0) {

            digit = x%10;
            if (digit == 3 || digit == 4 || digit == 7) return false;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) validdigit = true;
            x/=10;

        }


        if (validdigit) return true;

        return false;

    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            if (isgood(i)) cnt++;
        }
        return cnt;
    }
};