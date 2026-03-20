class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        
        int i = 0;
        int correctidx = 0;

        while (i<arr.size()) {

            correctidx = arr[i]-1;

            if (arr[i] != arr[correctidx]) {
                swap(arr[i] , arr[correctidx]);
            } else { 
                i++;
            }
        }

        // for (int i=0; i<arr.size(); i++) {
        //     cout << arr[i] << " ";
        // }

        vector<int> ans;

        for (int i=0; i<arr.size(); i++) {

            if (arr[i] != i+1) {
                ans.push_back(i+1);
            }

        }

        return ans;







    }
};