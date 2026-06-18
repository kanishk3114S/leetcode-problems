class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        vector<pair<int,int>> arr;

        for (int i=0; i<nums2.size(); i++) {

            arr.push_back({nums2[i] , i});

        }

        //element and the index//


        sort(nums1.begin() , nums1.end());
        sort(arr.begin() , arr.end());

        vector<bool> satisfied(arr.size() , false);

        int ptr1 = 0 , ptr2 = 0;

        vector<int> ans(arr.size() , -1);

        while (ptr1 < nums1.size() && ptr2 < arr.size()) {

            if (nums1[ptr1] > arr[ptr2].first) {

                ans[arr[ptr2].second] = nums1[ptr1];
                satisfied[ptr1] = true;
                ptr1++;
                ptr2++;

            } else {
                ptr1++;

            }

        }

        for (int i=0; i<satisfied.size(); i++) {

            if (!satisfied[i]) {

                for (int j=0; j<ans.size(); j++) {
                    if (ans[j] == -1) {
                        ans[j] = nums1[i];
                        break;
                    }
                }

            }

        }


        return ans;





    }
};