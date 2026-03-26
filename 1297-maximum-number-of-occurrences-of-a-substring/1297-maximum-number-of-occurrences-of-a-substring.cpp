class Solution {
public:

    bool satisfy(string s , int req) {

        vector<int> hash(26,0);
        int cnt = 0;
        for (int i=0; i<s.length(); i++) {

            hash[s[i]-'a']++;

        }

        for (int i=0; i<hash.size(); i++) {
            if (hash[i] > 0) cnt++;
        }

        if (cnt <= req) return true;
        
        return false;

    }

    int maxFreq(string s, int req, int minsize, int maxSize) {
        
        unordered_map<string,int> mpp;

        int l = 0 , r = minsize-1;
        string sample ="";
        for (int i=l; i<=r; i++) {

            sample+=s[i];

        }

        mpp[sample]++;
        
        int maxcnt = INT_MIN;
        if (satisfy(sample,req)) {
            maxcnt = max(maxcnt , mpp[sample]);
        }

        while (r < s.length()) {

            sample.erase(sample.begin());
            l++;
            r++;
            if (r==s.length()) break;

            sample+=s[r];
            mpp[sample]++;
            
            if (satisfy(sample,req)) {

                maxcnt = max(maxcnt , mpp[sample]);

            }

        }

        return maxcnt==INT_MIN? 0 : maxcnt;
        


    }
};