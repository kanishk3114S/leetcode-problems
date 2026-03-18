class Solution {
public:
    int findPermutationDifference(string s, string t) {
        
        unordered_map<int,int> mpp;
        for (int i=0; i<t.length(); i++) {
            mpp[t[i]] = i;
        }

        int diff = 0;

        for (int i=0; i<s.length(); i++) {
            
            diff += abs(i-mpp[s[i]]);

        }

        return diff;

    }
};