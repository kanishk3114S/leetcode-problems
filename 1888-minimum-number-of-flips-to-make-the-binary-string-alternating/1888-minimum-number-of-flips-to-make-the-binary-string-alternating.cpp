class Solution {
public:
    int minFlips(string s) {
        // very trivial to do type1 operations again and again//

        

        int l = 0 , r = s.length()-1;
        int diff1 = 0 , diff2 = 0; 

        for (int i=l; i<=r; i++) {

            char exp1 = (i%2) ? '0' : '1'; //even pe 0 and odd pe 1//
            char exp2 = (i%2) ? '1' : '0';

            if (s[i] != exp1) diff1++;
            if (s[i] != exp2)  diff2++;

        }

        // cout << diff1 << " "<< diff2;
            s+=s;
        int ans = min(diff1 , diff2);

        while (r < s.length()) {

            char prev1 = (l%2) ? '0' : '1'; //even pe 0 and odd pe 1//
            char prev2 = (l%2) ? '1' : '0';

            if (s[l] != prev1) diff1--;
            if (s[l] != prev2) diff2--;

            l++;
            r++;

            if (r == s.length()) break;

            char exp1 = (r%2) ? '0' : '1'; //even pe 0 and odd pe 1//
            char exp2 = (r%2) ? '1' : '0';

            if (s[r] != exp1) diff1++;
            if (s[r] != exp2)  diff2++;

            ans = min(ans , min(diff1 , diff2));

        }

        return ans;

    }
};