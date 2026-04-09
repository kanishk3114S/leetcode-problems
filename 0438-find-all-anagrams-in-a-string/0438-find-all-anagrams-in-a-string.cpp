class Solution {
public:

    bool isanagram(map<char,int>&map1 ,map<char,int>&map2 ) {

        if (map1.size() != map2.size()) return false;


        return map1==map2;   

    }

    vector<int> findAnagrams(string s, string p) {
        
        map<char,int> map1 , map2;
        vector<int> ans;

        for (int i=0; i<p.length(); i++) map2[p[i]]++;

        int l = 0 , r = p.length()-1;

        for (int i=l; i<=r; i++) {

            map1[s[i]] ++;

        }

        if (isanagram(map1 , map2)) ans.push_back(l);


        while (r < s.length()) {

            map1[s[l]]--;
            if (map1[s[l]] == 0)map1.erase(s[l]);
            l++;
            r++;

            if (r == s.length()) break;

            map1[s[r]]++;

            if (isanagram(map1 , map2)) ans.push_back(l);


        }
        return ans;
    }
};