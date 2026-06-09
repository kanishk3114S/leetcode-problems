class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        long long ans = 0;
        long long minel =  LLONG_MAX , maxel = LLONG_MIN;
        for (int i=0; i<nums.size(); i++) {

            minel = min(minel , (long long)nums[i]);
            maxel = max(maxel , (long long)nums[i]);

        }

        ans = (maxel-minel)*k;

        return ans;
    }
};