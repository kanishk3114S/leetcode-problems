class Solution {
public:

    void helper(string s , int n, vector<string>& result , string sample) {

        //base case//

        if (sample.length() == n) {
            result.push_back(sample);
            return;
        }

        //calls//

        for (int i=0; i<s.length(); i++) {

            if (!sample.empty() && sample[sample.length()-1] == s[i]) {
                continue; //skip the selection//
            } 
            sample.push_back(s[i]);
            helper(s , n , result , sample);
            sample.pop_back();
            


        }

        

    }

    string getHappyString(int n, int k) {
        vector<string> result;
        string s = "abc";
        helper(s , n , result , "");
        sort(result.begin() , result.end());
        return k>result.size() ? "" : result[k-1];

    }
};