class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int el:nums) {

            if (mpp.count(el)) {ans.push_back(el);}
            else mpp[el]++;

        }

        for (int i=0; i<nums.size(); i++) {
            if (!mpp.count(i+1)) ans.push_back(i+1);
        }

        return ans;


    }
};