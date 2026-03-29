class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        char odd1 = 0 , odd2 = 2;
        char even1 = 1 , even2 = 3;

        vector<char> ch(26);

        for (int i=0; i<s1.length(); i++) {
            ch[s1[i]-'a']++;
        }
        for (int i=0; i<s2.length(); i++) {
            ch[s2[i]-'a']--;

            if (ch[s2[i]-'a'] < 0) return false;

        }   

        for (int i=0; i<s1.length(); i++){

            if (s1[odd1] != s2[odd1] && s1[odd1] != s2[odd2]) return false;

            if (s1[even1] != s2[even1] && s1[even1] != s2[even2]) return false;
            if (s1[even2] != s2[even1] && s1[even2] != s2[even2]) return false;
            if (s1[odd2] != s2[odd1] && s1[odd2] != s2[odd2]) return false;


        }

        return true;

    }
};