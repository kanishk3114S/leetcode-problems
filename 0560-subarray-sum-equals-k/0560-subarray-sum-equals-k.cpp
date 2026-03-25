class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int prefsum = 0 , cnt = 0;
        for (int i=0; i<nums.size(); i++) {

            prefsum += nums[i];
            if (mpp.count(prefsum-k)) {

                cnt += mpp[prefsum-k];

            }
            mpp[prefsum]++;


        }
        return cnt;

    }
};