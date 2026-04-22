class Solution {
public:
// bool isgood(string s , string t) {

//     int changed = 0;

//     for (int i=0; i<s.length(); i++) {

//         if (s[i] != t[i]) changed++;

//     }

//     if (changed <=2) return true;

//     return false;

// }

vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
    
    vector<string> ans;
    for (int i=0; i<q.size(); i++) {
        string s = q[i];
        for (int j=0; j<d.size(); j++) {
            string t = d[j];
    int changed = 0;

    for (int i=0; i<s.length(); i++) {

        if (s[i] != t[i]) changed++;

    }

    if (changed <=2) {
        ans.push_back(s);
        break;
    } else continue;
        }
    }
    return ans;

}
};