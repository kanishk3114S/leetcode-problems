class Solution {
public:
    string processStr(string s) {

        stack<char> st;
        
        for (int i=0; i<s.length(); i++) {

            if (islower(s[i])) {
                st.push(s[i]);
            } else if (s[i] == '*') {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s[i] == '#') {
                string temp = "";
                while (!st.empty()) {
                    temp+=st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                temp=temp+temp;
                for (char ch:temp) {
                    st.push(ch);
                }
            } else if (s[i] == '%') {
                queue<char> q;
                while (!st.empty()){
                    q.push(st.top());
                    st.pop();
                }
                while (!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};