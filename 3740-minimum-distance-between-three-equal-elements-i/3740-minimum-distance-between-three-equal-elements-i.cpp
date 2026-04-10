class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist = 0 , ans = INT_MAX;

        int i=0;
        while (i < nums.size()) {

            int el = nums[i];
            for (int j=i+1; j<nums.size()-1; j++) {

                for (int k=j+1; k<nums.size(); k++) {

                    if (nums[j] == el && nums[k] == el) {

                        dist = abs(i-j) + abs(j-k) + abs(k-i);
                       ans = min(dist , ans);

                    }

                }
            }

            i++;
        }

        return ans==INT_MAX ? -1 : ans;

    }
};