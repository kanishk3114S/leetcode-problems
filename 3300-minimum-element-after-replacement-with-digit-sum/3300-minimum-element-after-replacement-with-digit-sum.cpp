class Solution {
public:

    int calc(int n) {
        int ans = 0;
        while (n > 0) {
            int digit = n%10;
            ans+=digit;
            n/=10;
        }
        return ans;

    }

    int minElement(vector<int>& nums) {
        
        int minel = INT_MAX;
        for (int i=0; i<nums.size(); i++) {

            int sum = calc(nums[i]);
            minel = min(minel , sum);



        }

        return minel;

    }
};