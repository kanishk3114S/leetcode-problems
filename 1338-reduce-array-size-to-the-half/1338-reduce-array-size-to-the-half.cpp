class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> mpp;

        for (int num:arr){
            mpp[num]++;
        }

        int sz = arr.size();

        priority_queue<pair<int,int>> pq;

        for (auto it:mpp) {

            pq.push({it.second,it.first});

        }

        int req = sz/2;
        int ans = 0;

        while (sz > req) {

            sz -= pq.top().first;
            pq.pop();
            ans ++;

        }

        return ans;

    }
};