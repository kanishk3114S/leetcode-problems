class Solution {
public:
    string decodeString(string s) {
        
        bool found = false;
        stack<pair<int,string>> st;
        string temp = "";

        for (int i=0; i<s.length(); i++) {
            
           if (isdigit(s[i])) {
            string num = "";
            while (isdigit(s[i])) {
                num += s[i];
                i++;
            }
            i--;
            st.push({stoi(num) , ""});

           } else if (s[i] == '[') {

            //opening is started//
            found = true;

           } else if (islower(s[i])) {

            if (st.empty()) {
                temp += s[i];
            } else {
                string S = st.top().second;
                int k = st.top().first;
                st.pop();
                S+=s[i];
                st.push({k , S});
            }

           } else if (s[i] == ']') {

            //bracket closed--> 2 cases//
            string var = st.top().second;
            int k = st.top().first;
            st.pop();
            string res = "";
            for (int i=0; i<k; i++) {
                res += var;
            }
            if (st.empty()) {
                temp += res;
            } else {
                string outer = st.top().second;
                int outerk = st.top().first;
                st.pop();
                outer = outer+res;
                st.push({outerk , outer});
            }

           }

        }

        return temp;

    }
};