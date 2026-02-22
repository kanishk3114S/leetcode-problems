class Solution {
public:
    long long maximumSubarraySum(vector<int>& s, int k) {
        
        int l = 0 , r = k-1;
        long long sum = 0 , maxsum = 0;
        unordered_map<int,int> mpp;

        for (int i=l; i<=r; i++) { 
            sum += s[i];
            mpp[s[i]]++;
        }

        if (mpp.size() == k) {
            maxsum = max(maxsum , sum);
        }

        // else maxsum = 0 , sum  = 0 //

        while (r < s.size()) { 
            mpp[s[l]]--;
            sum-= s[l];
            if (mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
            r++;

            if (r == s.size()) break;

            sum += s[r];
            mpp[s[r]]++;

            if (mpp.size() == k) {
                maxsum = max(maxsum , sum);
            }
            
        }

        return maxsum;


    }
};