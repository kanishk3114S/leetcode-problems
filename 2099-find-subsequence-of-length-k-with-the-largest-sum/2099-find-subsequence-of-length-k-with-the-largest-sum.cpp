class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> ans;
        vector<int> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for (int i=0; i<nums.size(); i++) {

            pq.push({nums[i] , i});
            if (pq.size() > k) {
                pq.pop();
            }

        }

        while (!pq.empty()) {

            ans.push_back(pq.top());
            pq.pop();

        }

        sort(ans.begin() , ans.end() , [](const pair<int,int>&a , const pair<int,int>&b){
            return a.second < b.second;
        });

        for (int i=0; i<ans.size(); i++) {
            result.push_back(ans[i].first);
        }

        return result;

    }
};