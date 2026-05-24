class Solution {
public:
    int rearrangeCharacters(string s, string targ) {
        
        unordered_map<char,int> mpp , t_map;

        for (char ch:s) mpp[ch]++;

        for (char ch:targ) t_map[ch]++;

        int ans = INT_MAX;

        for (int i=0; i<targ.length(); i++) {

            char ch = targ[i];
            if (!mpp.count(ch) || t_map[ch] > mpp[ch]) return 0;
            else {
                ans = min(ans ,mpp[ch]/t_map[ch]);
            }

        }

        return ans;


    }
};