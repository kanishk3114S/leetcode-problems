class Solution {
public:
    #define ll long long 
    vector<int> getAverages(vector<int>& arr , int k) {
        
        vector<int> result(arr.size() , -1);

        if (k==0) return arr;
        else if (2*k >= arr.size()) return result;

        int l = 0 , r = 2*k;
        ll sum = 0 , average = 0;
        
        for (int i=l; i<=r; i++) {

            sum += arr[i];

        }

        average = sum/(r-l+1);

        result[k++] = average;

        while (r < arr.size()) {

            sum -= arr[l];
            l++;
            r++;
            if (r == arr.size()) break;
            sum+=arr[r];
            average = sum/(r-l+1);
            result[k++] = average;

        }

        return result;

    }
};