class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<map<char,int>,vector<string>> mpp;

        for (auto s:strs) {

            map<char,int> freq;
            for (char ch:s) {
                freq[ch]++;
            }

            mpp[freq].push_back(s);

        }

        vector<vector<string>> ans;

        for(auto it:mpp) {

            ans.push_back(mpp[it.first]);

        }

        return ans;

    }
};