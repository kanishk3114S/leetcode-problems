#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string begin, string goal, vector<string>& wordList) {
        
        queue<string> q;

        set<string> st(wordList.begin() , wordList.end());

        if (!st.count(goal)) return 0;

        int moves = 1;

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

                        temp[i] = (char)j+'a';

                        if (temp==goal) return moves+1;

                        if (st.count(temp)) {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }

            moves++;
        }



        return 0;

    }
};