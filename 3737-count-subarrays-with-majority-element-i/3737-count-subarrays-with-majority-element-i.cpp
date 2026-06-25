class Solution {
public:
    int countMajoritySubarrays(vector<int>& arr, int target) {

        int cnt = 0;
        
        for (int i=0; i<arr.size(); i++) {
            unordered_map<int,int> mpp;
            for (int j=i; j<arr.size(); j++) {

                mpp[arr[j]]++;

                if (mpp[target] > (j-i+1)/2) {
                    cnt++;
                }

            }

        }

        return cnt;

    }
};