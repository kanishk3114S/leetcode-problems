class Solution {
public:

    bool isequal(vector<vector<int>>& mat, vector<vector<int>>& targ) {

        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat[0].size(); j++) {
                if (mat[i][j] != targ[i][j]) {
                    return false;
                }
            }
        }
        return true;

    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& targ) {
        
        if (isequal(mat,targ)) return true;
        int n = mat.size();
        // cout << n;

        //for first rotation//
        bool r1 = true , r2 = true , r3 = true;

        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat[0].size(); j++) {

                if (mat[i][j] != targ[j][n-i-1]) r1 = false;
                if (mat[i][j] != targ[n-1-i][n-1-j]) r2 = false;
                if (mat[i][j] != targ[n-1-j][i]) r3 = false;

            }
        }


        if (r1 || r2 || r3) return true;
        else if (!r1  && !r2 && !r3) return false;
        
        return false;
    }
};