class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& arr, vector<vector<int>>& queries) {
        
        int len = arr[0].length();
        vector<int> ans;

        for (int i=0; i<queries.size(); i++) {
        
            priority_queue<pair<string,int>> pq;
            int k = queries[i][0];
            int rem = len-queries[i][1];

            vector<long long> temp;

            for (int j=0; j<arr.size(); j++) {

                string s = arr[j].substr(rem,queries[i][1]);

                pq.push({s , j});

                if (pq.size() > k) pq.pop();

            }

            ans.push_back(pq.top().second);

        }

        return ans;

    }
};