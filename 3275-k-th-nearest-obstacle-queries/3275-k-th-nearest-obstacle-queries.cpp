class Solution {
public:

    double d(int x , int y) {

        return abs(x) + abs(y);

    }

    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        
        using ppd = pair<double , pair<int,int>>;

        priority_queue<ppd> pq;
        vector<int> ans;

        for (int i=0; i<queries.size(); i++) {

            int x = queries[i][0];
            int y = queries[i][1];

            pq.push({d(x,y) , {x,y}});

            if (pq.size() < k) {
                ans.push_back(-1);
            } else if (pq.size() == k) {

                ans.push_back(pq.top().first);

            } else {

                pq.pop();
                ans.push_back(pq.top().first);

            }

        }

        return ans;

        

    }
};