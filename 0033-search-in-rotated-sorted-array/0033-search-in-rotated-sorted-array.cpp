class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        //at every cut...either left will be sorted or right will be sorted//

        int low = 0 , high = arr.size()-1;

        while (low <= high) {

            int mid = low - (low-high)/2;
            if (arr[mid] == target) return mid;
            if (arr[low] <= arr[mid]) {
                //left half is sorted//

                if (arr[low] <= target && arr[mid] >= target) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }

            } else {

                if (arr[mid] <= target && arr[high] >= target) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }

            }
        }

        return -1;

    }
};