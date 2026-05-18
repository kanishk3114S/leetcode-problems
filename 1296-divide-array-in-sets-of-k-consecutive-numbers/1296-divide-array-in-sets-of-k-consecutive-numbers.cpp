class Solution {
public:
    
    using pp = pair<int,int>;

    bool hand(vector<pp>&arr , int s) {

        if (arr.size() != s) return false;

        for (int i=0; i<s-1; i++) {
            if (arr[i+1].first-arr[i].first > 1) return false;
        }

        return true;

    }

    bool isPossibleDivide(vector<int>& arr, int n) {
            
        if (arr.size()%n != 0) return false;

        unordered_map<int,int> mpp;
        for (int num:arr) mpp[num]++;

        priority_queue<pp,vector<pp>,greater<pp>> pq;

        for (auto it:mpp) {
            pq.push({it.first , it.second});
        }

        while (!pq.empty()) {
            vector<pp> corner;
            while (!pq.empty() && corner.size() < n) {

                corner.push_back({pq.top().first,pq.top().second-1});
                pq.pop();

            }

            if (hand(corner , n)) {
                for (int i=0; i<n; i++) {
                    if (corner[i].second > 0) {

                        pq.push({corner[i].first , corner[i].second});

                    }
                }
            } else {
                return false;
            }

        }

        return true;

    }
};