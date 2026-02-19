class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int cntzeros = 0;
        int l = 0 , r = 0;
        int len = 0 , maxlen = 0;

        while (r < nums.size()) {

            if (nums[r] == 1) {
                len = r-l+1;
                r++;
            } else if (nums[r] == 0) {
                cntzeros++;

                while (cntzeros > k) {
                    
                    if (nums[l] == 1) {
                        l++;
                    } else {
                        cntzeros--;
                        l++;
                    }
                }
                len = r-l+1;
                r++;
            }
            maxlen = max(maxlen , len);

        }

        return maxlen;


    }
};