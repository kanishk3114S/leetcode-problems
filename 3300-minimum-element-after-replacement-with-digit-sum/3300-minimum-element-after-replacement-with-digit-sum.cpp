class Solution {
public:

    int sum(int n) {

        int ans = 0;

        int digit = 0;

        while(n>0) {
            digit=n%10;
            ans+=digit;

            n/=10;
        }

        return ans;

    }

    int minElement(vector<int>& nums) {
        int minel = INT_MAX;
        for (int i=0; i<nums.size(); i++) {

            minel = min(minel , sum(nums[i]));

        }

        return minel;

    }
};