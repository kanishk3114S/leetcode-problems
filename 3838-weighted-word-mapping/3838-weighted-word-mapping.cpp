class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& wt) {
        //string+hashmap//

        string ans = "";
        int sum = 0, idx = 0 , newidx = 0;;
        for (int i=0; i<words.size(); i++)  {
            int j = 0;
            sum = 0;
            newidx = 0;
            while( j < words[i].size()) {
            idx = words[i][j] - 'a';
            sum += wt[idx];
            j++;
            }

            newidx = sum%26;

            ans += (25-newidx)+'a';

        }

        return ans;



        

    }
};