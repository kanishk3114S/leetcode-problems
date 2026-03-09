class Solution {
public:

    int smallestBalancedIndex(vector<int>& nums) {
        const long long MOD = 1e9+7;
        vector<long long> prefixsum;
        vector<long long> product(nums.size()+1);

        //calculating the prefix sums//

        int prefsum = 0;

        for (int i=0; i<nums.size(); i++) {

            prefsum += (nums[i]%MOD)%MOD;
            prefixsum.push_back(prefsum);

        }

        long long prod = 1;

        for (int i=nums.size()-1; i>-1; i--) {

            prod *= (nums[i]%MOD)%MOD;
            product[i] = prod;

        }

        product[nums.size()] = 1;

        for (int i=1; i<nums.size(); i++) {

            int left = prefixsum[i-1];
            int right = product[i+1];

            if (left == right) return i;

        }

        return -1;


    }
};