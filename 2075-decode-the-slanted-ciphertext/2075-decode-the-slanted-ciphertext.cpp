class Solution {
public:
    string decodeCiphertext(string etext, int m) {

        int n = etext.length()/m;
        vector<vector<char>> mat(m , vector<char>(n , ' '));


        for (int i=0; i<m; i++) {

            for (int j=0; j<n; j++) {

            mat[i][j] = etext[i*n + j];

            }

        }

        //for every row traversel we need a column travrssal//

        string ans = "";

        for (int i=0; i<n; i++) {
            int row = 0 , col = i;
            while (row < m && col < n) {
                ans+= mat[row][col];
                row++;
                col++;
            }

        }

        int z = ans.length()-1;

        for (int i=z; i>-1; i--) {

            if (ans[i] != ' ') break;
            else {ans.erase(i , 1);
            }

        }

        return ans;

    }
};