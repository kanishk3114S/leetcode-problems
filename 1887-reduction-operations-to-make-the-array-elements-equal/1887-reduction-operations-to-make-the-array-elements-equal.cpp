class Solution {
public:
    int reductionOperations(vector<int>& arr) {

    unordered_map<int,int> mpp;

    for (int num:arr) mpp[num]++;

    if (mpp.size()==1) return 0;

    vector<pair<int,int>> v(mpp.begin() , mpp.end());

    sort(v.begin() , v.end());

    int sum = 0 , ans = 0;

    for (int i=v.size()-1; i>0; i--) {

        sum += v[i].second;

        ans += sum;

    }

    return ans;

    }
};