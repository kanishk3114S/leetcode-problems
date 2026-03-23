class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans = "";

        unordered_map<char,int> mpp;

        for (int i=0; i<=k; i++) {

            if (i < s.length() && !mpp.count(s[i])) {
                ans+=s[i];
            }

            mpp[s[i]] = i;

        }

        
        for (int i = 0; i<ans.length(); i++) { //all unique will be in the answer//

            mpp[ans[i]] = i;

        }
        int range = 0;

        for (int i=k+1; i<s.length(); i++) {

            if (i < s.length() && !mpp.count(s[i])) {
                ans+=s[i];
                mpp[ans[ans.length()-1]] = ans.length()-1;
            } else { //s[i] exists//

                range = (ans.length()-mpp[s[i]]);
                // cout << "for s[i] : " << s[i] <<  "range is : " << ans.length() << " - " << mpp[s[i]] << endl;
                if (range <= k) continue;
                else {
                    ans+=s[i];
                    mpp[ans[ans.length()-1]] = ans.length()-1;
                }

            }
        }

        return ans;

    }
};