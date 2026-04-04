class Solution {
public:
    int scoreOfParentheses(string t) {
        
        stack<int> s;

        int score = 0;

        for (int i=0; i<t.length(); i++) {
            score = 0;
            if (t[i] == '(') {
                s.push(0);
            } else { // we got the closing bracket

                if (s.top() == 0) {
                    s.pop();
                    s.push(1);
                } else {

                    while (!s.empty() && s.top() != 0) {

                        score += 2*s.top();
                        s.pop();
                       
                    }
                    s.pop(); //remove the zero//
                    s.push(score);

                }

            }

        }

        int ans = 0;

        while (!s.empty()) {ans+=s.top(); s.pop();}

        return ans;

    }
};