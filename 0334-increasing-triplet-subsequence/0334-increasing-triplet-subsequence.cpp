class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        long long first = LLONG_MAX , second = LLONG_MAX;

        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                second = num;
            }

            if (num > second) return true;

        }

        return false;

    }
};