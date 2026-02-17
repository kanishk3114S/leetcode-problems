class Solution {
public:

    int ans(int num , int cnt) {
        if (num == 0 ) return cnt;
        if (num%2 == 0) {
           return ans(num/2 , cnt+1);
        } else {
           return ans(num-1 , cnt+1);
        }
        return cnt;
    }


    int numberOfSteps(int num) {
        
        return ans(num , 0);

    }
};