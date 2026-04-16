class Solution {
public:
    
    int closest(vector<int>&v , int size , int val) {

        int i =0; //we have to find the index//
        int n = v.size();
        if (v.size() == 1) return -1;
        // int ans = INT_MAX;
        // int dist = 0 , rint = 0;
        int l = 0 , r = v.size()-1;
        int mid = 0;
        while (l<=r) {

            mid = (l+r)/2;

            if (v[mid] == val) {

                i = mid;
                break;
                
            } else if (v[mid] > val) {

                r = mid-1;

            } else l = mid+1;

        }

        int left = (i-1+n)%n;
        int right = (i+1)%n;

       int d1 = abs(v[left] - val);
       int d2 = abs(v[right] - val);

        d2 = min(d2, size - d2);
        d1 = min(d1, size - d1);

        return min(d1, d2);

    }

    vector<int> solveQueries(vector<int>& arr, vector<int>& queries) {
       unordered_map<int , vector<int>> mpp;
        vector<int> result;
        int n = arr.size();
        for (int i=0; i<arr.size(); i++) {

            mpp[arr[i]].push_back(i); // in the sorted fashion//

        }

        for (int i=0; i<queries.size(); i++) {

            int element = arr[queries[i]];

            int ans = closest(mpp[element] ,  n , queries[i]);
            result.push_back(ans);

        }

        return result;



    }
};