class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        
        int l = 0 , r = k-1;
        int sum = 0 , average = 0;

        int ans = 0;

        for (int i=l; i<=r; i++)  {
            sum+=arr[i];
        }
        average = sum/k;

        if (average >= th) ans++;

        cout <<  average << endl;

        while (r < arr.size()) {

            l++;
            r++;

            if (r == arr.size()) break;

            sum = sum-arr[l-1]+arr[r];

            // cout << "sum is : " << sum << endl;

            average = sum/k;


            if (average >= th) ans++;
            // cout << "the average is : " << average << " the ans is : " << ans << endl;


        }

        return ans;

    }
};