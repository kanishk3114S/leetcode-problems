class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        

        //array can be strictly increasing / deacrising//

        if (arr.size() > 1 && arr[0] > arr[1]) return 0;
        if (arr.size() > 1 && arr[arr.size()-1] > arr[arr.size()-2]) return arr.size()-1;

        arr.insert(arr.begin() , INT_MIN);
        arr.push_back(INT_MAX);
        int n = arr.size();

        if (n==3) return 0;


        // for (auto it:arr) cout << it << " ";

        //LOGIC----> if element lies in increasing peak then peak exist in right,,,,,,,,,element lies in left//

        int low = 1 , high = n-2;

        while (low <= high) {

            int mid = low-(low-high)/2;

            cout << low << " " << high << " & mid is " << mid << endl;

            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid-1;
            } else {

                if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {

                    //increasing half//

                    low = mid+1;


                } else {

                    high = mid-1;

                }
            }
        }

        return -1;

    }
};