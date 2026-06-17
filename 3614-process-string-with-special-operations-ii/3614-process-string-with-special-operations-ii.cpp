class Solution {
    #define ll long long
public:
    char processStr(string s, long long k) {
        //WE WILL process a backward pass instead of a forward pass//

        //#---> remove k/2 from k//
        //* ---> k+1//
        //k -= k/2 //

        vector<ll> length;
        ll len = 0;
        for (char ch:s) {

            if (islower(ch)) {
                len++;
            } else if (ch == '*') {
                if (len > 0) len--;
            } else if (ch == '#') {

                len = len+len;
            }

            length.push_back(len);

        }

        // now will we track the k//
        // we will track from where the k came from//

        for (int i=s.length()-1; i>-1; i--) {

        ll before = (i == 0 ? 0 : length[i - 1]);
        ll after = length[i];

        if (k >= after) return '.';

        if (s[i] == '#') {
            if (before > 0) {
                k = k%before;
            }
        } else if (s[i] == '%') {

            k = after-1-k;

        } else if  (islower(s[i]) && k == after-1) {
            return s[i];
        }

        }

        return '.';


    }
};