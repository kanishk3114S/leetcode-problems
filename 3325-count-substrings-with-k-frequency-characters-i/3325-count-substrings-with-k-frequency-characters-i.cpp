class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int l = 0 , r = 0;
        unordered_map<char,int> mpp;
        vector<int> hash(26,0);
        int c = 0;
        int ans = 0;
        while (r < s.length()) {

            mpp[s[r]]++;
            if (mpp[s[r]] == k) {
                c++;
            }

            while (c>0 && l<=r) {
                ans+=s.length()-r;
                mpp[s[l]]--;
                if (mpp[s[l]] == k-1) c--;
                l++;
            }
            r++;

        }

        return ans;

    }
};