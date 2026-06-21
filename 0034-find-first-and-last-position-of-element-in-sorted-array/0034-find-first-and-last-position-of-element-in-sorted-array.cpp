class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        
        //ans-->(lb , up-1)//

        vector<int> res = {-1,-1};
        
        if (arr.size()==0) return res;

        // only two possibilities are there....may be an answer ,  can not be an answer//

        int st = 0 , end = arr.size()-1;
        int ans = arr.size();

        while (st <= end) {

            int mid = st-(st-end)/2;

            if (arr[mid] >= target) {
                ans = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }

        }

        if (ans < arr.size() && arr[ans] == target) {
            res[0]=ans;
        }

        ans = arr.size();

        st = 0 , end = arr.size()-1;

        while (st <= end) {

            int mid = st-(st-end)/2;

            if (arr[mid] > target) {
                ans = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }

        }

        if (ans > 0 && arr[ans-1] == target) {
            res[1] = ans-1;
        }

        return res;

    }
};