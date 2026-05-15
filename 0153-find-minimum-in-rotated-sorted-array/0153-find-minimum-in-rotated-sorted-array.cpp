class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int l = 0, r = arr.size()-1;

        while (l <= r){

            int mid = (l+r)/2;

            if (arr[mid] > arr[r]) { //2nd half

                l = mid+1;

            } else if (arr[mid] < arr[r]) {

                r = mid;

            } else  {
                r--;
            }

        }

        return arr[l];


    }
};