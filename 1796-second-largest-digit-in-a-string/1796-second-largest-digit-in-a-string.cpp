class Solution {
public:
    int secondHighest(string t) {
        
    set<int> s;

    for (int i=0; i<t.length(); i++) {

        if (t[i]-'0' >= 0 && t[i]-'0' <= 9) s.insert(t[i]-'0');

    }

    if (!s.empty()) {
        s.erase(prev(s.end()));
    }
    if (s.empty()) return -1;
    else return *prev(s.end());

    return 0;

    }
};