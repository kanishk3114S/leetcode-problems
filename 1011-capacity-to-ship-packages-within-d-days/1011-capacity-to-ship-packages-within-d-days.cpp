class Solution {
public:

    bool check(vector<int>& arr, int days , int cap) {

        int curr = 0 , taken = 0;
        for (int i=0; i<arr.size(); i++) {

            curr += arr[i];
            if (curr > cap) {
                taken++;
                curr = arr[i];
            }

        }

        if (curr <= cap) taken++;

        if (taken <= days) return true;

        return false;

    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxi = INT_MIN , sum = 0;
        for (auto it:weights) {
            maxi = max(it,maxi);
            sum += it;
        }

        int low = maxi , high = sum;
        int ans = sum;

        while (low <= high) {

            int mid = low-(low-high)/2;

            if (check(weights , days , mid)) {

                // cout << "check is true for  low : " << low << " high : " << high << " and mid is " << mid << endl;

                ans = mid;
                high = mid-1;

            } else {
                
                // cout << "check is false for  low : " << low << " high : " << high << " and mid is " << mid << endl;
                low = mid+1;
            }




        }

            return ans;
    }
};