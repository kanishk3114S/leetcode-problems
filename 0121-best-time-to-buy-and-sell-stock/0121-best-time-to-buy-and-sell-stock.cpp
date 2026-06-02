class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> purchase(n);

        purchase[0] = INT_MAX;
        int currmin = INT_MAX;

        for (int i=1; i<n; i++) {

            currmin = min(currmin , prices[i-1]);
            purchase[i] = currmin;

        }

        int ans = INT_MIN;

        for (int i=0; i<prices.size(); i++) {

            ans = max(ans , prices[i]-purchase[i]);

        }
        
        return ans<=0?0:ans;

    }
};