class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        //make 3 pointers i,j,k.....//

        int i = 0 , j = i+1 , k=arr.size()-1;

        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());
        int sum = 0;
        
        while (i<j) {
        while (i>0 && i<arr.size() && arr[i] == arr[i-1]) {
                    i++;
           }
           j = i+1;
           k = arr.size()-1;
            while (j < k) {
                sum = arr[i]+arr[j]+arr[k];
                if (sum == 0) {
                    
                    ans.push_back({arr[i] , arr[j] , arr[k]});
                    j++;
                    k--;
                while (j < arr.size() && arr[j] == arr[j-1]) {
                    j++;
                }
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;

        }
    return ans;
    }
};