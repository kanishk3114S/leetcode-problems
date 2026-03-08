class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        unordered_map<string,int> mpp;
        int poss = 1<<n;
        int bit = 0;
        for (int i=0; i<poss; i++) {
            string sample = "";
            for (int j=0; j<n; j++) {

                bit = ((i>>j)&1);
                sample += bit + '0';
        

            }
            mpp[sample]++;

        }

        //all samples got generated//

        for (int i=0; i<nums.size(); i++) {

            mpp[nums[i]]--;

        }

        for (auto it:mpp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return "";

    }
};