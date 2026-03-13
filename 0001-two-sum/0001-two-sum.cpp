class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hashing solution//
        vector<int> ans;
        unordered_map<int,int> mpp; //we will store the key and its indices//

        for (int i=0; i<nums.size(); i++) {
            int need = target-nums[i];
            if (mpp.count(need)) {
                ans.push_back(mpp[need]); //original pushed --> indice
                ans.push_back(i); //jis duplicate value pe hai , uska indice //
            }
            mpp[nums[i]] = i; //num --> indices//
        }

        return ans;
    }
};