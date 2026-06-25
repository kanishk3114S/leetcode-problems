class Solution {
public:

    bool check(vector<int>& bloomday, int target, int k , int ans) {

        //k--> streak , m---> target we to match//
        int streak = 0 , cnt = 0;
        for (int i=0; i<bloomday.size(); i++) {

            if (bloomday[i] <= ans) {
                //it got bloomed//
                streak++;
            } else streak =0;
            if (streak == k) {
                streak = 0;
                cnt++;
            }
        }
        return cnt >= target;
    }

    int minDays(vector<int>& bloomday, int m, int k) {
        
        int maxi = INT_MIN;
        for (auto it:bloomday) maxi = max(maxi , it);

        int low = 1 , high = maxi;
        int ans = -1;

        while (low <= high) {

            int mid = low-(low-high)/2;

            if (check(bloomday , m , k , mid)) {
                // cout << "for : mid " << mid << " giving true " << endl;
                ans = mid;
                high = mid-1;
            } else { 

                low = mid+1;

            }


        }

        return ans;


    }
};