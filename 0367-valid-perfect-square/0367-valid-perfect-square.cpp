class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int i = 0 , j = num;

        while (i <= j) {

        long long mid = i+(j-i)/2;

        if (1LL*mid*mid > num) {
            j = mid-1;
        } else if (1LL*mid*mid == num) {
            return true;
        } else {
            i = mid+1;
        }
    }

        return false;

    }
};