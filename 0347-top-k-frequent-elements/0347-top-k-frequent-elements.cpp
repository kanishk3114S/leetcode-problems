class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
    using pp = pair<int,int>;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    unordered_map<int,int> mpp;
    for (int num:nums) mpp[num]++;
    vector<int> ans;

    for (auto it:mpp) {

        pq.push({it.second , it.first});

        if (pq.size() > k) pq.pop();

    }

    while (!pq.empty()) {

        ans.push_back(pq.top().second);
        pq.pop();

    }

    return ans;

    }
};