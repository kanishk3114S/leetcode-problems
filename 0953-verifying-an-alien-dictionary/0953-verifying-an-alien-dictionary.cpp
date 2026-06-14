class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char,int> mpp;

        int idx = 0;

        for (char ch:order) {

            mpp[ch] = idx;
            idx++;

        }



        for (int i=0; i<words.size()-1; i++) {

            string s1 = words[i];
            string s2 = words[i+1];

            // if (s1.length() > s2.length() && s1.substr(0,s2.length()) == s2) return false;
            bool found = false;
            for (int i=0; i<min(s1.length() , s2.length()); i++) {

                if (s1[i] != s2[i]) {

                    // cout << s1[i] << " " << s2[i] << " " << mpp[s1[i]] << " " << mpp[s2[i]];
                    found = true;
                    if (mpp[s1[i]] > mpp[s2[i]]) return false;
                    else break;

                }
            }

            if (!found && s1.length() > s2.length()) return false;

        }

        return true;

    }
};