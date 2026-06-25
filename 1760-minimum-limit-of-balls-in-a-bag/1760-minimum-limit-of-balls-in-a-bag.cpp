class Solution {
public:

    bool check(vector<int>& arr, int maxOp , int limit) {

        int operations = 0;

        for (int i=0; i<arr.size(); i++) {

            if (arr[i] > limit) {
                if (arr[i]%limit == 0) {
                    operations += (arr[i]/limit);
                    operations--;
                } else {
                    operations += (arr[i]/limit);
                }
            }

            if (operations > maxOp) return false;

        }

        return true;

    }

    int minimumSize(vector<int>& arr, int maxOp) {

        int maxi = 0;
        for (auto it:arr) {
            maxi = max(it,maxi);
        }


        int low = 1 , high = maxi;
        int ans = maxi;

        while (low <= high) {

            int mid = low-(low-high)/2;

            if (check(arr,maxOp ,mid)) {
                // cout << "check is true for " << "low " << low << " high " << high << " mid : " << mid<<endl;
                ans = mid;
                high = mid-1;
            } else {
                // cout << "check is false for " << "low " << low << " high " << high << " mid : " << mid<<endl;
                low = mid+1;
            }
        }

        // cout << check(arr,maxOp , 3);

        return ans;
        
    }
};