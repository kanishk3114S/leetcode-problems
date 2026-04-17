class Solution {
public:

    int reverse(long long n) {

        long long x = 0;

        //start extracting the digits//
        long long digit = 0;
        while (n > 0) {

            digit = n%10;
            x = (x*10)+digit;
            n/=10;
        }

        return x;

    }

    int minMirrorPairDistance(vector<int>& arr) {
        
        vector<pair<bool,bool>> v(1e5 , {false,false});
        unordered_map<long long ,vector<int>> mpp;

        for (int i=0; i<arr.size(); i++) {

            if (!mpp.count(arr[i])) {   
                int el = reverse(arr[i]);
                mpp[el].push_back(i);

                v[el].second = true; //the reverse exists//

            } else {
                mpp[arr[i]].push_back(i);
                v[arr[i]].first = true; //the element itself exists//

            }

        }

        int ans = INT_MAX;

        for (auto it:mpp) {

            // cout << it.first << endl;

        if  (v[it.first].first && v[it.first].second) {

            for (int i=0; i<it.second.size()-1; i++) {

                int el1 = it.second[i];
                int el2 = it.second[i+1];

                ans = min(ans , abs(el2-el1));

            }

        }

        }

        return ans==INT_MAX?-1:ans;

    }
};