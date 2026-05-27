class Solution {
public:
    int minAddToMakeValid(string st) {
        
        stack<char> s;

        for (char ch:st) {

            if (!s.empty() && ch == ')' && s.top() == '(') s.pop();
            else {
                s.push(ch);
            }

        }

        return s.size();

    }
};