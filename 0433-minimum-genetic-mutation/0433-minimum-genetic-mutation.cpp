class Solution {
public:
    int minMutation(string begin, string goal, vector<string>& wordList) {
        
        queue<string> q;

        set<string> st(wordList.begin() , wordList.end());

        if (!st.count(goal)) return -1;

        int moves = 0;

        q.push(begin);

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                string s = q.front();
                // cout << s << " " << moves << endl;
                q.pop();
                
                for (int i=0; i<s.length(); i++) {
                    string temp = s;
                    for (int j=0; j<26; j++) {

                        temp[i] = (char)j+'A';
                        cout << temp << " ";

                        if (temp==goal) {
                            return moves+1;
                        }

                        if (st.count(temp)) {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                    // cout << endl;
                }
            }

            moves++;
        }



        return -1;
    }
};