class Solution {
public:
    int divisorSubstrings(int n, int k) {
        string s = to_string(n);
        int l = 0 , r = k-1;
        string num = "";
        for (int i=l; i<=r; i++) {
            num+=s[i];
        }
        int cnt = 0;
        if (n%stoi(num) == 0) cnt++;

        while (r < s.length()) {

            num.erase(num.begin());
            l++;
            r++; 

            if (r == s.length()) break;

            num+= s[r];

            int el = stoi(num);
            if (el != 0 && n%el == 0) cnt++;
            
        }

        return cnt;
    }
};