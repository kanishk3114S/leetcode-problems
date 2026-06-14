class Solution {
public:

    const long long MOD = 1e9+7;

    int rangeSum(vector<int>& arr, int n, int left, int right) {

        long long sum = 0;
        vector<int> summation;

        for (int i=0; i<arr.size(); i++) {
            sum = 0;
            for (int j=i; j<arr.size(); j++) {

                sum += 1LL*arr[j];
               summation.push_back((int)sum);

            }


        }

        sort(summation.begin() , summation.end());
        // for (auto it:summation)cout<<it<< " ";
        int ans = 0;
        for (int i=left-1; i<=right-1; i++) {

            ans = ans + (summation[i]%MOD);
            ans = ans%MOD;

        }

        return ans;

    }
};