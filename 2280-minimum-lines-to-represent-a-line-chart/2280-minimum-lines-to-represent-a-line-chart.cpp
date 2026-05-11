class Solution {
public:

    long double slope(vector<int>&a , vector<int>&b) {

        long double ans = 0;

        ans = (long double)(b[1]-a[1])/(b[0]-a[0]);

        return ans;

    }

    int minimumLines(vector<vector<int>>& prices) {
        vector<long double> v;

        if (prices.size()==1) return 0;

        sort(prices.begin() , prices.end());
        
        for (int i=0; i<prices.size()-1; i++) {

           long double var = slope(prices[i] , prices[i+1]);
            v.push_back(var);

        }

        int ans = 1;

        // for (double num:v) cout << num << " ";

        for(int i=1; i<v.size(); i++) {
            
            if (v[i] != v[i-1]) ans++;

        }

        return ans;

    }
};