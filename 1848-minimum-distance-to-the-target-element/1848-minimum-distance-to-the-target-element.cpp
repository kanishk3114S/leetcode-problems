class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        unordered_map<int,vector<int>> mpp;
        for (int i=0; i<nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (int i=0; i<mpp[target].size(); i++) {

            ans = min(ans , abs(mpp[target][i] - start));

        }

        return ans;
        
    }
};