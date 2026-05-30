class Solution {
public:
    int strStr(string s, string needle) {
        
        string sample = "";

        if (needle.length() > s.length()) return -1;

        for (int i=0; i<needle.size(); i++) {
            sample += s[i];
        }

        if (sample == needle) return 0;
        int l=0 , r = sample.length()-1;
        while (r < s.length()) {

            sample.erase(0 , 1);
            l++;
            r++;
            if (r == s.length()) break;
            sample += s[r];

            if (sample == needle) return l;



        }

        return -1;

    }
};