class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9+7;
        int size = queries.size();


        for (int i=0; i<size; i++) {

            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;

            while (idx <= r) {

                nums[idx] = ((nums[idx]%MOD) * v) % (MOD);
                idx += k;

            }
        }

        int ans = 0;
        for (int i=0; i<nums.size(); i++) {

            ans^=nums[i];


        }

        return ans;


    }
};