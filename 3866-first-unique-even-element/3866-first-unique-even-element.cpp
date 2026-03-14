class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        for (int num:nums) {
            mpp[num]++;
        }

        for (int i=0; i<nums.size(); i++) {
            if (mpp[nums[i]] == 1 && nums[i]%2 == 0) return nums[i];
        }

        return -1;


    }
};