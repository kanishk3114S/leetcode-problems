class Solution {
public:

    bool check(vector<int>& candies, long long k , long long ans) {

        long long spent = 0;
        for (int i=0; i<candies.size(); i++) {

            spent += candies[i]/ans;
        }

        if (spent >= k) return true;

        return false;


    }


    int maximumCandies(vector<int>& candies, long long k) {
        
        long long sum = 0;

        for (auto it:candies) {
            sum+=it;
        }
        if (sum < k) return 0;

        long long low = 1 , high = sum;
        long long ans = sum;

        while (low <= high) {

            long long mid = low-(low-high)/2;

            if (check(candies,k,mid)) {

                ans = mid;
                low=mid+1;

            } else {
                high = mid-1;
            }
        }

        return ans; 
        
    }
};