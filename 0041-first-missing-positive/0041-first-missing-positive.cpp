class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int len = arr.size();

        //perform the cyclic sort//
        int correctidx = 0;
        int i=0;
        while (i < len) {

            if (arr[i] > 0 && arr[i] < len) { //in the givern range//

                correctidx = arr[i] - 1;
                if (arr[i] != arr[correctidx]) {

                    swap(arr[i] , arr[correctidx]);
                } else {
                    i++;
                }

            } else {
                i++;
            }


        }

        for (int j=0; j<len; j++) {

            if (arr[j] != j+1) {
                return j+1;
            }
            
        }


        //if all numbers are present return the nums//

        return len+1;
    }
};