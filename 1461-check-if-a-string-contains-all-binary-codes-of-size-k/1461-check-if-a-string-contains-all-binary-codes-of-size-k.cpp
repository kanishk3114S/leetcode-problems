class Solution {
public:
    bool hasAllCodes(string s, int k) {
      //map to contain all the strings s//

    if (k > s.length()) return false;

    unordered_map<string,int> mpp;

    string sample = "";

    int l = 0 , r = k-1;

    for (int i=l; i<=r; i++) {
        sample += s[i];
    }

    mpp[sample]++;

    while (r < s.length()) {

        sample.erase(0 , 1); // 0 is the sample index//
        l++;
        r++;
        if (r == s.length()) break;
        sample.push_back(s[r]);
        // cout << sample << "  ";
        mpp[sample]++;
    }

    int poss = 1<<k;

    if (mpp.size() == poss) return true;

    return false;


    }
};