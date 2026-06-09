class Solution {
public:
    int myAtoi(string s) {
        
        string ans="";
        bool isneg = false , ispos = false , found = false;

        for (int i=0; i<s.length(); i++) {

            if (s[i] == ' '  && !found) continue;
            else if (s[i] == '-' && !found) {isneg = true; found = true;}
            else if (s[i] == '+' && !found) {ispos = true; found = true;}
            else if (isdigit(s[i])) {ans += s[i]; found = true;}
            else {
                break;
            }
        }

    for (int i=0; i<ans.length(); i++) {
        if (ans[i] != '0') break;
        else {
            ans.erase(ans.begin()+i);
            i--;
        }
    }

    cout << ans << " ";

    if (ans == "") return 0;

    string temp = "";

    for (int i=0; i<ans.length(); i++) {

        temp+=ans[i];
        long long number = stoll(temp);
        
        if (number > INT_MAX) {
            // cout << isneg << " ";
            if (isneg) return INT_MIN;
            else return INT_MAX;
        }

    }

    long long num = stoll(ans);
    if (isneg) num*=-1;

    return (int)num;

    // return 0;

    }
};