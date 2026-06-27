class Solution {
public:

    bool check(vector<int>& arr , int threshold , int d) {

        long long hold = 0;

        for (int i=0; i<arr.size(); i++) {


            hold += ((arr[i]+(d-1))/d);

            if (hold > threshold) return false;

        }

        return true;


    }


    int smallestDivisor(vector<int>& arr , int threshold) {
        
        int low = 1 , high = 1e6;
        int ans = 1e6;

        while (low<=high) {

            int mid = low-(low-high)/2;

            if (check(arr,threshold , mid)) {

                ans = mid;
                high = mid-1;

            } else {

                low = mid+1;

            }


        }

        return ans;


    }
};