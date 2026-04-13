class Solution {
public:
    vector<string> printVertically(string s) {
        
        vector<string> ans;
        int streak = 0 , cnt = 0 , m = 0;

        for (char ch:s) {
            if (ch == ' ') {streak=0; cnt++;}
            else streak++;
            m = max(m , streak);
        }

        int n = cnt+1;
        vector<vector<char>> resultant(m , vector<char>(n , ' '));

        int row = 0 , col = 0 ;

        for (int i=0; i<s.length(); i++) {

            if (s[i] == ' ') {
                row = 0;
                col++;
                continue;
            }

            resultant[row][col] = s[i];
            row++;
        }

        for (int i=0; i<m; i++) {
            string t = "";
            bool foundchar = false;

            for (int j=n-1; j>=0; j--) {
                if (resultant[i][j] != ' ') foundchar = true;
                if (foundchar) t.push_back(resultant[i][j]);
            }

            reverse(t.begin() , t.end());
            ans.push_back(t);
        }

        return ans;
    }
};