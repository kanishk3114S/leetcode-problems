class Solution {
public:
    int getLucky(string s, int k) {
        
        string let = "";
        for (char ch:s) {

            int num = (ch-'a') + 1;
            let+=to_string(num);

        }

        cout << let << " ";

        int ans = 0;

        for (int i=0; i<k; i++) {
            
            ans = 0;
            for (char ch:let) {

                ans += ch - '0';

            }

            let = to_string(ans);
        }

        return ans;

    }
};