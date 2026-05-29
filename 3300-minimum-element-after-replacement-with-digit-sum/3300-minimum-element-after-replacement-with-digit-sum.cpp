class Solution {
public:


    int minElement(vector<int>& nums) {
        
        int minel = INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            int ans = 0;
            while (n > 0) {
                int digit = n%10;
                ans+=digit;
                n/=10;
            }
            minel = min(minel , ans);



        }

        return minel;

    }
};