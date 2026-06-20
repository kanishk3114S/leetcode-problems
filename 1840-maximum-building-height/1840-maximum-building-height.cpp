class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        
        //instead of building the vector<int> heights [result=MLE]//
        // we will move between the restricted areas and we will see the max height between them.//
        using ll = long long;
        rest.push_back({1,0});
        sort(rest.begin() , rest.end());
        vector<pair<ll,ll>> h(rest.size() , {-1,-1});
        for (int i = 0; i < rest.size(); i++) {
            h[i] = {rest[i][0], rest[i][1]};
        }

        int maxht = INT_MIN;


        for (int i=0; i<rest.size()-1; i++) {

            int dist = rest[i+1][0]-rest[i][0];

            h[i+1].second = min(h[i+1].second , h[i].second + dist);

        }

        //backward//

        for (int i=rest.size()-1; i>0; i--) {

            int dist = rest[i][0]-rest[i-1][0];

            h[i-1].second = min(h[i-1].second , h[i].second + dist);

        }

        int maxpeak = 0;

        for (int i=0; i<h.size()-1; i++) {

            int dist = h[i+1].first-h[i].first;
            int peak = (h[i].second+h[i+1].second+dist)/2;

            maxpeak = max(peak , maxpeak);


        }

        ll final_dist = n - h.back().first;
        ll final_peak = h.back().second + final_dist;
        maxpeak = max((long long)maxpeak, final_peak);

        return maxpeak;

    }
};