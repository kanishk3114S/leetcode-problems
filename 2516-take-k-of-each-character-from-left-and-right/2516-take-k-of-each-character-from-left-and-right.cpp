class Solution {
public:
    int takeCharacters(string s, int k) {

        // so the answer will be the n-longestuseless window//

        int cnta = 0 , cntb = 0 , cntc = 0;

        for (char ch:s) {
            if (ch == 'a') cnta++;
            if (ch == 'b') cntb++;
            if (ch == 'c') cntc++;
        }

        //longest valid window with the constraints//

        int valida = cnta-k , validb = cntb-k , validc = cntc-k;

        if (valida < 0 || validb < 0 || validc < 0) return -1;

        int l = 0 , r = 0;

        cnta = 0 , cntb = 0 , cntc = 0;

        int maxlen = 0;

        while (r < s.length()) {

            if (s[r] == 'a') cnta++;
            if (s[r] == 'b') cntb++;
            if (s[r] == 'c') cntc++;

            while (cnta > valida || cntb > validb || cntc > validc) {

                l++;
                if (s[l-1] == 'a') cnta--;
                if (s[l-1] == 'b') cntb--;
                if (s[l-1] == 'c') cntc--;
            }

            maxlen = max(maxlen , r-l+1);

            r++;

        }

        return s.length()-maxlen;

    }
};