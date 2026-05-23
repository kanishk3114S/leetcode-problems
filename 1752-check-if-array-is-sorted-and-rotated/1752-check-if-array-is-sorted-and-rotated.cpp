class Solution {
public:
    bool check(vector<int>& nums) {
        
        int k = 0;

        for (int i=1; i<nums.size(); i++) {

            if (nums[i-1] > nums[i]) {k = i; break;}

        }
        
        if (k==0) return true;

        k=nums.size()-k;

        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());

        for (int num:nums) cout<<num<<" ";

        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1] > nums[i]) return false;
        }

        return true;

    }
};