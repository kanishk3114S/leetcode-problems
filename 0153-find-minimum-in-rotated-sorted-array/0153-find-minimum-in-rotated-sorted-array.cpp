class Solution {
public:
    int findMin(vector<int>& arr) {
        
        //intution---> choose min from sorted and eliminate the search space//

        int low = 0 , high = arr.size()-1;
        int ans = INT_MAX;

        while (low <= high) {

            int mid = low-(low-high)/2;

            if (arr[low] <= arr[mid]) {
                //left half is sorted//

                ans = min(arr[low] , ans);
                low = mid+1;
            } else {

                ans = min(arr[mid] , ans);
                high = mid-1;

            }
        }

        return ans;


    }
};