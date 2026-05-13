class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        unordered_map<char,int>first,last;

        for (int i=0; i<s.length(); i++) {

            if (first.count(s[i])) {
                continue;
            } else {
                first[s[i]] = i;
            }

        }
                for (int i=s.length()-1; i>-1; i--) {

            if (last.count(s[i])) {
                continue;
            } else {
                last[s[i]] = i;
            }

        }
    
    int maxi=-1;
    for (auto it:first) {

        if (last.count(it.first)) {

            maxi = max(maxi , last[it.first]-it.second-1);

        }

    }

    return maxi;

    }
};