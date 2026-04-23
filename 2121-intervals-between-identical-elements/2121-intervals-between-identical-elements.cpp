class Solution {
public:
int findindex(vector<int>&arr , int val) {

    int l = 0 , r = arr.size()-1;

    while (l<=r) {

        int mid = l + (r - l)/2;

        if (arr[mid] == val) return mid;
        else if (arr[mid] > val) r = mid-1;
        else l = mid+1;
    }

    return -1;
}

vector<long long> getDistances(vector<int>& nums) {

    unordered_map<int,vector<int>> mpp;
    unordered_map<int,vector<long long>> pref_map;
    unordered_map<int,vector<long long>> suff_map;

    for (int i=0; i<nums.size(); i++) {
        mpp[nums[i]].push_back(i);
    } 

    for (auto it:mpp) {
        long long prefsum = 0;
        for (int i=0; i<it.second.size(); i++) {
            prefsum += it.second[i];
            pref_map[it.first].push_back(prefsum); 
        }
    }

    for (auto it:mpp) {
        long long suffsum = 0;
        for (int i=it.second.size()-1; i>=0; i--) {
            suffsum += it.second[i];
            suff_map[it.first].push_back(suffsum); 
        }
        reverse(suff_map[it.first].begin() , suff_map[it.first].end());
    }

    vector<long long> ans;

    for (int i=0; i<nums.size(); i++) {

        int val = nums[i];
        int idx = findindex(mpp[val] , i);
        int size = mpp[val].size();

        long long left = (1LL*i*idx) - (idx > 0 ? pref_map[nums[i]][idx-1] : 0);
        long long right = (idx < size-1 ? suff_map[nums[i]][idx+1] : 0) - (1LL*i*(size-idx-1));

        ans.push_back(left + right);
    }

    return ans;
}
};