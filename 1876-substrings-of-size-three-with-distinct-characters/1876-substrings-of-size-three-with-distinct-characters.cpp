class Solution {
public:

    int countGoodSubstrings(string s) {
        unordered_map<char,int> mpp;
        int l = 0 , r = 2 , ans = 0;
        for (int i=l; i<=r; i++) { 
            mpp[s[i]]++;
        }

        if (mpp.size() == 3) ans++;

        while (r < s.length()) {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) mpp.erase(s[l]);
            l++; // we moved the l..//
            r++;
            if (r == s.length()) break;
            mpp[s[r]]++;

            if (mpp.size() == 3) {
                ans++;
            }

        }
        
        return ans;

    }
};