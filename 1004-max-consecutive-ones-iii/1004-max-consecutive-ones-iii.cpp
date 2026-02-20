class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int cntzeros = 0;
        int l = 0 , r = 0;
        int len = 0 , maxlen = 0;

        while (r < nums.size()) {

            
            if (nums[r] == 0) {
                cntzeros++;
            }

            while (cntzeros > k) {
                if (nums[l] == 0) {
                    cntzeros--;
                }
                l++;
            }


            len = r-l+1;
            maxlen = max(len , maxlen);
            r++;


        }

        return maxlen;


    }
};