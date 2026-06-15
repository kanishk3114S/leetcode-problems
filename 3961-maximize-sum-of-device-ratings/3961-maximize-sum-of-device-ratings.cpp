class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        
        long long ans = 0;

        if (units[0].size() == 1) {

            for (auto it:units) {
                ans+= it[0];
            }

            return ans;

        }


        for (auto&it:units) {
            sort(it.begin() , it.end());
        }

        struct cmp {
                bool operator()(pair<int,int>& a, pair<int,int>& b) {
                    
                    if (a.first == b.first)
                        return a.second > b.second;

                    return a.first > b.first;
                }
            };

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                cmp
            > pq;

        int min_of_second = INT_MAX , globalmin = INT_MAX;

        for (auto it:units) {

            pq.push({it[0] , it[1]});
            globalmin = min(globalmin , it[0]);
            min_of_second = min(it[1] , min_of_second);

        }

        if (pq.size() == 1) return pq.top().first;

        while (!pq.empty()) {
            ans+=pq.top().second;
            pq.pop();
        }

        ans = ans-min_of_second+globalmin;

        return ans;



    }
};