class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    int cnt1 = 0 , cnt2 = 0 , el1 = INT_MAX , el2 = INT_MAX;

    for (int num:nums) {

        if (cnt1 == 0 && num != el2) {
            el1 = num;
            cnt1 = 1;
        } else if (cnt2 == 0 && num != el1) {
            el2 = num;
            cnt2 = 1;
        } else if (num == el1) cnt1++;
          else if (num == el2) cnt2++;
          else cnt1-- , cnt2--;
    }

    cnt1 = 0 , cnt2 =0;
    int req = floor(nums.size()/3);
    for (int num:nums) {
        if (el1 == num) cnt1++;
        else if (el2 == num) cnt2++;
    }


    vector<int> ans;

    if (cnt1>req) ans.push_back(el1);
    if (cnt2>req) ans.push_back(el2);

    sort(ans.begin() , ans.end());
    return ans;

    }
};