class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        // smalles number that divides nums//

        unordered_set<int>s(nums.begin() , nums.end());
        long long ans = 0;
        
        for (int i=0; i<nums.size(); i++) {

            int x = nums[i];
            int best = nums[i];

            for (int j=1; j<=sqrt(nums[i]); j++) {

                if (x%j == 0) {

                    if (s.count(j)) {//j exists in that array//

                    best = min(best , j);
                        
                    }

                    int remaining = x/j;
                    if (s.count(remaining)) {
                        best=min(best,remaining);
                    }              
                    
                }
                
            }

            ans += best;
            
        }
        return ans;
    }
};