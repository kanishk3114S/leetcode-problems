class Solution {
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string b;
    private:
    void dfs(string s , vector<string> seq) {

        if (s == b) {
            reverse(seq.begin() , seq.end());
            ans.push_back(seq);
            reverse(seq.begin() , seq.end());
            return;
        }

                int level = mpp[s];

                for (int i=0; i<s.length(); i++) {

                    string temp =s;

                    for (char ch='a'; ch<='z';  ch++) {

                        temp[i] = ch;

                        if (mpp.count(temp) && mpp[temp] + 1 == level) {
                            seq.push_back(temp);
                            dfs(temp , seq);
                            seq.pop_back();
                        }
                    }
                }
    }
public:
    vector<vector<string>> findLadders(string beginword, string endword, vector<string>& words) {
        
        b =beginword;
        queue<string> q;
        q.push(beginword);
        unordered_set<string> st(words.begin() , words.end());
        st.erase(beginword);

        while (!q.empty()) {

            int sz = q.size();

            for (int i=0; i<sz; i++) {

                string s = q.front();
                q.pop();
                int level = mpp[s];

                for (int i=0; i<s.length(); i++) {

                    string temp =s;

                    for (char ch='a'; ch<='z';  ch++) {

                        temp[i] = ch;

                        if (st.count(temp)&& temp==endword) {
                            mpp[temp] = level+1;
                            vector<string> seq = {endword};
                            dfs(endword , seq);
                            return ans;
                        }

                        if (st.count(temp)) {
                            q.push(temp);
                            mpp[temp] = level+1;
                            st.erase(temp);
                        }
                    }
                }
            }

        }

        return ans;

    }
};