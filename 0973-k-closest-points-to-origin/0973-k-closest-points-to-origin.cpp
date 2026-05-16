class Solution {
public:

    double d(int x , int y) {

        double ans = 0;
        ans = sqrt((x*x) + (y*y));

        return ans;

    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // PUSH THE {DIFF , {X,Y}};//

        using ppi = pair<double,pair<int,int>>;
        vector<vector<int>> ans;

        priority_queue<ppi> pq;

        for (int i=0; i<points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            pq.push({d(x,y) , {x,y}});

            if (pq.size() > k) pq.pop();

        }

        while (!pq.empty()) {

            ans.push_back({pq.top().second.first , pq.top().second.second});
            pq.pop();

        }

        return ans;
    
    }
};