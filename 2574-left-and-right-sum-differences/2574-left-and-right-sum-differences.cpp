class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr)  {
        
        vector<int> prefix;
        long long totalsum = 0;
        long long sum = 0;

        for (int i=0; i<arr.size(); i++) {

            sum+=arr[i];
            prefix.push_back(sum);
            totalsum += arr[i];

        }

        vector<int> ans(arr.size());

        int leftsum = 0 , rightsum = 0;

        for (int i=0; i<arr.size(); i++) {

            i==0 ? leftsum = 0 : leftsum = prefix[i-1];
            i==arr.size()-1 ? rightsum = 0 : rightsum = totalsum-prefix[i];

            // cout << leftsum << " " << rightsum << endl;

            ans[i] = abs(leftsum - rightsum);

        }

        return ans;


    }
};