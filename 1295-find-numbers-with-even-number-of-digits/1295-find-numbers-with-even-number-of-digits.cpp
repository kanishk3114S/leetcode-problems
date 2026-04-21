class Solution {
public:

    int cntDigits(int n) {
        int digit = 0;
        while(n>0){
            digit++;
            n/=10;
        }
        return digit;

    }

    int findNumbers(vector<int>& nums) {
        
        int ans = 0;

        for (int n:nums) {

            int digit = cntDigits(n);
            if (digit%2 == 0) ans++;
            
        }

        return ans;

    }
};