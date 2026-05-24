class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        map<int,int> mpp;
        for (int i=0; i<nums.size(); i++) {

            mpp[nums[i]]++;
            
        }

        vector<int> arr;

        for (auto it:mpp) {

            if (mpp[it.first] > k) {
                for (int i=0; i<k; i++) {
                    arr.push_back(it.first);
                }
            } else {
            for (int i=0; i<it.second; i++) {
                    arr.push_back(it.first);
                }
            }

        }

        return arr;
        
    }
};