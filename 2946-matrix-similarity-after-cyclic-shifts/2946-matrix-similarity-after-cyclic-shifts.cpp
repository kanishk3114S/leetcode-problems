class Solution {
public:

    void rotateleft(vector<int>&arr , int k) {
        reverse(arr.begin() , arr.end());
        reverse(arr.begin() , arr.begin()+k);
        reverse(arr.begin()+k , arr.end());
    }

    void rotateright(vector<int>&arr , int k) {
         k = arr.size()-k;
        reverse(arr.begin() , arr.end());
        reverse(arr.begin() , arr.begin()+k);
        reverse(arr.begin()+k , arr.end());

    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> copymat(m , vector<int>(n , 0));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {

                copymat[i][j] = mat[i][j];

            }
        }

        k = k%n; //normalize the k integer//

        for (int i=0; i<m; i++) {

            if (i%2 == 0) {
                //even row.......left shift will apply//
                rotateleft(mat[i] , k);
            } else {
                rotateright(mat[i] , k);
            }
            
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {

                if (mat[i][j] != copymat[i][j]) return false;

            }
        }

        return true;



    }
};