class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& candy) {
        
        int ans = 0;

        sort(greed.begin() , greed.end());
        sort(candy.begin() , candy.end());

        int ptr1 = 0 , ptr2 = 0;

        while (ptr1 < greed.size() && ptr2 < candy.size()) {

            if (greed[ptr1] <= candy[ptr2]) {
                ptr1++;
                ptr2++;
                ans++;
            } else {
                ptr2++;
            }

        }

        return ans;

    }
};