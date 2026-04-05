class Solution {
public:

    bool bounds(int row , int col , int n) {

        if (row < 0 || col < 0 || row >= n || col >= n) return false;

        return true;

    }

    vector<int> executeInstructions(int n, vector<int>& pos, string s) {
        
        vector<int> ans;
        int srow = 0 , scol = 0;
        int moves = 0;
        for (int i=0; i<s.length(); i++) {
            srow = pos[0] , scol = pos[1];
            moves = 0;
            for (int j=i; j<s.length(); j++) {

                if (s[j] == 'D') srow++;
                if (s[j] == 'L') scol--;
                if (s[j] == 'R') scol++;
                if (s[j] == 'U') srow--;

                if (!bounds(srow , scol , n)) break;
                else moves++;

            }

            ans.push_back(moves);

        }

        return ans;

    }
};