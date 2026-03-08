class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        unordered_map<string,int> mpp;
        for (int i=0; i<nums.size(); i++) {

            mpp[nums[i]]++;

        }
        int poss = 1<<n;
        int bit = 0;
        for (int i=0; i<poss; i++) {
            string sample = "";
            for (int j=0; j<n; j++) {

                bit = ((i>>j)&1);
                sample += bit + '0';
        

            }
            if (!mpp.count(sample)) {
                return sample;
            }

        }
    return "";
    }
};