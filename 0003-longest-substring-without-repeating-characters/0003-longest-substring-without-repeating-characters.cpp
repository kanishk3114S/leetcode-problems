class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mpp;

        int l = 0 , r = 0;
        int maxlen = 0;

        for (int i=0; i<s.length(); i++) {
            
            if (!mpp.count(s[i]) || mpp[s[i]] < l) {

                mpp[s[i]] = i;  //insert in the hashmap//
                r = i;
                maxlen = max(maxlen , r-l+1);

            } else if (mpp.count(s[i]) && mpp[s[i]] >= l) {
                l = mpp[s[i]]+1;
                mpp[s[i]] = i; //overwrite with the current index//
                maxlen = max(maxlen , r-l+1);
            }

        }

        return maxlen;



    }
};