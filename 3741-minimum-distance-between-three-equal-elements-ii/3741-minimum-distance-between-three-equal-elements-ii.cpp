#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int calc(vector<int>&v) {

        int l = 0 , r = 1 , p = 2;

        int ans = INT_MAX;

        ans = min(ans , abs(v[l] - v[r]) + abs(v[r] - v[p]) + abs(v[p] - v[l]));

        while (p < v.size()) {

            l++;
            r++;
            p++;

            if (p == v.size()) break;
           ans = min(ans , abs(v[l] - v[r]) + abs(v[r] - v[p]) + abs(v[p] - v[l]));

        }

        return ans;

    }

    int minimumDistance(vector<int>& arr) {

        int result = INT_MAX;
        
        unordered_map<int , vector<int>> mpp;

        for (int i=0; i<arr.size(); i++) {

            mpp[arr[i]].push_back(i); //store all the indices of elements//

        }


        for (auto it:mpp) {

            if (it.second.size() >= 3) {

                result = min(result  , calc(it.second));

            }

        }

        return result==INT_MAX ? -1 : result;

    }
};