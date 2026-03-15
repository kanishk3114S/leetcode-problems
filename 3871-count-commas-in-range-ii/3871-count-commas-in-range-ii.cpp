class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;

        //between 1e3 and 1e6 --> 1e6-1-1e3//

        long long first = 1e6-1e3;
        long long second = (1e9-1e6)*2;
        long long third = (1e12-1e9)*3;
        long long fourth = (1e15-1e12)*4;
        long long fifth = 5;

        if (n<1e3) return 0;

        if (n<1e6) {
            for (long long i=1e3; i<=n; i++) {
                cnt++;
            }
        } else if (n >= 1e6 && n < 1e9) {
            for (long long i=1e6; i<=n; i++) {
                cnt+=2;
            }
            cnt+=first;
        } else if (n>=1e9 && n < 1e12) {
            for (long long i=1e9; i<=n; i++) {
                cnt+=3;
            }
            cnt+=first+second;
        } else if (n>=1e12 && n < 1e15) {
            for (long long i=1e12; i<=n; i++) {
                cnt+=4;
            }
            cnt+=first+second+third;
        }

        if (n==1e15) {
            return first+second+third+fourth+fifth;
        }


        return cnt;
    }
};