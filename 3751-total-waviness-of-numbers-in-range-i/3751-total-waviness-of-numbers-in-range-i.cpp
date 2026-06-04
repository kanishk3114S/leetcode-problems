class Solution {
public:

    int wavy(string s) {

        int cnt = 0;

        for (int i=1; i<s.length()-1; i++) {

            int digit = s[i]-'0';
            int left = s[i-1]-'0';
            int right = s[i+1]-'0';

            if (digit > left && digit > right) {
                cnt++;
            } else if (digit < left && digit < right) {
                cnt++;
            }

        }

        return cnt;

    }

    int totalWaviness(int num1, int num2) {
        
        int ans = 0;
        if (num1 < 100 && num2 < 100) return 0;

        for (int i=max(100 , num1); i<=num2; i++) {

            string s = to_string(i);
            ans += wavy(s);

        }

        return ans;

    }
};