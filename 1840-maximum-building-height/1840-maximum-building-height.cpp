class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        using ll = long long;
        rest.push_back({1, 0});
        sort(rest.begin(), rest.end());

        vector<pair<ll, ll>> h(rest.size());
        for (int i = 0; i < rest.size(); i++) {
            h[i] = {rest[i][0], rest[i][1]};
        }

        for (int i = 0; i < h.size() - 1; i++) {
            ll dist = h[i+1].first - h[i].first;
            h[i+1].second = min(h[i+1].second, h[i].second + dist);
        }

        for (int i = h.size() - 1; i > 0; i--) {
            ll dist = h[i].first - h[i-1].first;
            h[i-1].second = min(h[i-1].second, h[i].second + dist);
        }

        ll maxpeak = 0;
        for (int i = 0; i < h.size() - 1; i++) {
            ll dist = h[i+1].first - h[i].first;
            ll peak = (h[i].second + h[i+1].second + dist) / 2;
            maxpeak = max(peak, maxpeak);
        }

        ll final_dist = n - h.back().first;
        ll final_peak = h.back().second + final_dist;
        maxpeak = max(maxpeak, final_peak);

        return maxpeak;
    }
};