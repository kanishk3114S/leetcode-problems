class Solution {
public:

    void helper(vector<vector<int>>& result , vector<int>& nums , vector<bool>& vis ,  vector<int> sample) {

        //base case//
        
        if (sample.size() == nums.size()) {
            result.push_back(sample);
            return;
        }



        //calls//

        for (int i=0; i<nums.size(); i++) {

            if (vis[i]) {
                continue; //skip the selection//
            }
            sample.push_back(nums[i]); //choose//
            vis[i] = true;
            helper(result , nums , vis ,  sample); //recurse//
            sample.pop_back(); //mvoe back to original state//
            vis[i] = false;
            
        }


    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<bool> vis(nums.size() , false);
        vector<int> sample;
        helper(result,nums, vis , sample);
        return result;
    }
};