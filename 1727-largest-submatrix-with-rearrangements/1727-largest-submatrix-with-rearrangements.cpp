class Solution {
public:


    int calc(vector<int>&arr) {
        int n = arr.size();
        vector<int> ns(n , n);
        for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;

        while (j != n && ns[j] >= ns[i]) {
            j = ns[j];  // jump!
        }

        ns[i] = j;
    }



        reverse(ns.begin() , ns.end());
        int area = 0 , maxarea = INT_MIN;
        int width = 0;
        for (int i=0; i<arr.size(); i++) {
            width = ns[i]-i;
            area = arr[i]*width;

            maxarea = max(area , maxarea);

        }

        return maxarea;

    }


    int largestSubmatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefgrid (m , vector<int>(n));

        //calculate the prefix grid..using the column wise traversal//

        for (int j=0; j<n; j++) {
            vector<int> temp;
            int streak = 0;
        
            for (int i = 0; i<m; i++) {

                if (mat[i][j] == 1) {
                    streak++;
                } else {
                    streak = 0; 
                }

                prefgrid[i][j] = streak;

            }
        } 

        //got the prefix grid..//

        int ans = INT_MIN;

        for (int i=0; i<m; i++) {
            sort(prefgrid[i].begin() , prefgrid[i].end());
            
            ans = max(ans , calc(prefgrid[i]));

        }

        return ans;

    }
};