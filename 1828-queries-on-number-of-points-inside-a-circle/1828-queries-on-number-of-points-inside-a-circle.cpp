class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& q) {
        vector<int> ans;
        for (int j=0; j<q.size(); j++) {

                int radius = q[j][2];
                int x1 = q[j][0];
                int y1 = q[j][1];
                int cnt = 0;
            for (int i=0; i<points.size(); i++) {


            int x = points[i][0];
            int y = points[i][1];

         long long dist = 1LL * (x-x1)*(x-x1) + 1LL * (y-y1)*(y-y1);

         if (dist <= radius*radius) cnt++;

            }

            ans.push_back(cnt);

        }

        return ans;

    }
};