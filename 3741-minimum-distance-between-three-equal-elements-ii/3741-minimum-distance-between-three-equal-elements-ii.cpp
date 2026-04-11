class Solution {
public:


    int calc(set<int>&s) {

        vector<int> v(s.begin(), s.end());

        int l = 0 , r = 2;
        int maxel = INT_MIN , minel = INT_MAX;
        int ans = 0;
        for (int i=l; i<=r; i++) {

            maxel = max(maxel , v[i]);
            minel = min(minel , v[i]);
        }
        ans = 2*(maxel - minel);

        // cout << maxel << " " << minel << endl;

        while (r < v.size()) {

            l++;
            r++;

            if (r == v.size()) break;

            maxel = v[r];
            minel = v[l];

            ans = min(ans , 2*(maxel - minel));

        }

        return ans;

    }

    int minimumDistance(vector<int>& arr) {

        int result = INT_MAX;
        
        unordered_map<int , set<int>> mpp;

        for (int i=0; i<arr.size(); i++) {

            mpp[arr[i]].insert(i); //store all the indices of elements//

        }


        for (auto it:mpp) {

            if (it.second.size() >= 3) {

                result = min(result  , calc(it.second));

            }

        }

        return result==INT_MAX ? -1 : result;

    }
};