class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        //(even,odd) --> left half//
        //(odd,even) ---> right half//

        int n = arr.size();

        if (arr.size() == 1 || arr[0] != arr[1]) return arr[0];
        if (arr[n-1] != arr[n-2]) return arr[n-1];

        int low = 1 , high = n-2;

        while (low <= high) {

            int mid = low-(low-high)/2;

            if (arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid]) {
                return arr[mid];
            } else {

                if (mid%2 == 0) {

                    if (arr[mid+1] == arr[mid]) {

                        //left half

                        low = mid+1;

                    } else {
                        high = mid-1;
                    }

                } else {

                    if (arr[mid+1] == arr[mid]) {

                        //left half

                        high = mid-1;

                    } else {
                        low = mid+1;
                    }


                }
            }
        }

    return -1;

    }
};