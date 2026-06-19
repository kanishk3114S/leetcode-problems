class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int alt = 0;
        int ans = INT_MIN;
        for (auto it:gain) {

            ans = max(alt , ans);
            alt+=it;

        }

        ans = max(alt , ans);

        return ans;

    }
};