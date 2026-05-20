class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        
        int n=a.size();
        int sum1 = 0 , sum2 = 0;
        int poss = 0;
        unordered_map<int,int> hash1,hash2;
        vector<int> ans;
        for (int i=0; i<n; i++) {

            hash1[a[i]]++;
            hash2[b[i]]++;


                if (i==0) {
                   a[i]==b[i] ? ans.push_back(1) : ans.push_back(0);
                } else {

                    if (hash1.count(b[i]) && !hash2.count(a[i])) poss=1;
                    else if (!hash1.count(b[i]) && hash2.count(a[i])) poss=1;
                    else if (!hash1.count(b[i]) && !hash2.count(a[i])) poss = 0;
                    else if (a[i] == b[i]) poss = 1;
                    else poss=2;

                    ans.push_back(ans[ans.size()-1]+poss);

                }

        }

        return ans;

    }
};