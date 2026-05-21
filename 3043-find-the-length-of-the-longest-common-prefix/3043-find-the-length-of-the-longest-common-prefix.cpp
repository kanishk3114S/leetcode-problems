class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //hashset solution.///

        unordered_set<string> mpp;

        for (int i=0; i<arr1.size(); i++) {

            string s = to_string(arr1[i]);

            string pref = "";

            for (int j=0; j<s.length(); j++) {

                pref+=s[j];

                // cout << pref << endl;

                if (!mpp.count(pref)) {
                    mpp.insert(pref);
                }
            }

        }

        // for (auto it:mpp) {
        //     cout << it << endl;
        // }

        int maxi = INT_MIN;

        for (int i=0; i<arr2.size(); i++) {

            string t = to_string(arr2[i]);

            string find = "";

            for (int j=0; j<t.length(); j++) {

                find += t[j];

                if (mpp.count(find)) {
                    maxi = max(maxi , j+1);
                } else {
                    break;
                }

            }

        }

        return maxi==INT_MIN?0:maxi;

    }
};