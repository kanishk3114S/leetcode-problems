class Solution {
public:

    bool isvowel(char c) {

        return c=='a' || c=='e' || c=='i' || c == 'o' || c == 'u';

    }

    bool isvalid(string words) {

    int len = words.length() - 1;

     return (isvowel(words[0]) && isvowel(words[len])) ;

    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        // unordered_map<int , string> mpp;
        vector<int> ans;

        vector<int> prefix;

        int cnt = 0;

        for (int i=0; i<words.size(); i++) {

            if (isvalid(words[i])) cnt++;

            prefix.push_back(cnt);

        }

        // int prev = 0;

        for (int i=0; i<queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l == 0) {
             ans.push_back(prefix[r]);
            } else ans.push_back(prefix[r]-prefix[l-1]);



        }

        return ans;

    }
};