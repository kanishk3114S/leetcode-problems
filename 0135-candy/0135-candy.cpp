class Solution {
public:
    int candy(vector<int>& arr) {
        
        vector<int> left(arr.size() , 0);
        vector<int> right(arr.size() , 0);

        left[0] = 1;
        for (int i=1; i<arr.size(); i++) {

           if (arr[i] > arr[i-1]) {
            left[i] = left[i-1]+1; 
           } else {
            left[i] = 1;
           }
        }

        right[arr.size()-1] = 1;

        for (int i=arr.size()-2; i>-1; i--) {

            if (arr[i] > arr[i+1]) {

                right[i] = right[i+1]+1;

            } else{ 
                right[i] = 1;
            }

        }

        int sum = 0;

        for (int i=0; i<arr.size(); i++) {
            sum += max(left[i] , right[i]); //max will satisfy both the left and the right//
        }
        return sum;





    }
};