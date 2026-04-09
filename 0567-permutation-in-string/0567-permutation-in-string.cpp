class Solution {
public:
    bool checkInclusion(string p, string s) {
        map<char,int> map1 , map2;

        if (p.length() > s.length()) return false;

        for (int i=0; i<p.length(); i++) map2[p[i]]++;

        int l = 0 , r = p.length()-1;

        for (int i=l; i<=r; i++) {

            map1[s[i]] ++;

        }

        if (map1 == map2) return true;;


        while (r < s.length()) {

            map1[s[l]]--;
            if (map1[s[l]] == 0)map1.erase(s[l]);
            l++;
            r++;

            if (r == s.length()) break;

            map1[s[r]]++;

            if (map1==map2) return true;


        }
        return false;
    }
};