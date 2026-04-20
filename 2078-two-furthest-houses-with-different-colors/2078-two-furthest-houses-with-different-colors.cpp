class Solution {
public:
    int maxDistance(vector<int>& col) {
        int el1 = col[0];
        int el2 = col[col.size()-1];

        int ans1 = 0 , ans2 = 0;

        for (int i=col.size()-1; i>=0; i--) {

            if (col[i] != el1) {ans1 = i; break;}

        }

        for (int i=0; i<col.size(); i++) {

            if (col[i] != el2) {ans2 = col.size()-1-i; break;}

        }

        cout << ans1 << " " << ans2;

        return max(ans1,ans2);

    }
};