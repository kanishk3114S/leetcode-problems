class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> ans;
        using ppl = pair<long long ,pair<int,int>>;
        set<pair<int,int>> s;

        vector<ppl> v;
        priority_queue<ppl , vector<ppl> , greater<ppl>> pq;

        int p1 = 0 , p2 = 0;

        pq.push({arr1[p1]+arr2[p2] , {p1 , p2}});

        while (!pq.empty() && ans.size() != k) {

            long long sum = pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            // cout << sum << " " << arr1[i] << " + " << arr2[j] << endl;
            pq.pop();

            if (j+1 < arr2.size()) {

                if (!s.count({i , j+1})) {
                pq.push({arr1[i]+arr2[j+1] , {i,j+1}});
                s.insert({i,j+1});

                }

            }

            if (i+1<arr1.size()) {

                if (!s.count({i+1 , j})) {
                pq.push({arr1[i+1]+arr2[j] , {i+1,j}});
                s.insert({i+1,j});

                }
            }

            ans.push_back({arr1[i] , arr2[j]});
        }

        return ans;

    }
};