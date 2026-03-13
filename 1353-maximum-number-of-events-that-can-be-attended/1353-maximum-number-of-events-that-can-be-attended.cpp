class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        //priority queue solution//

        int n = events.size();

        priority_queue<int,vector<int>,greater<int>> pq;

        auto cmp = [](const vector<int>&a , const vector<int>&b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];

        };

        int idx = 0 , day = 0;
        int cnt = 0;
        
        sort(events.begin() , events.end(), cmp);

        while (idx < n || !pq.empty()) { //till idx reached the last event + pq is empty...all events are being chosen + detached

            if (pq.empty()) {
                day = events[idx][0];
            }

            while (idx <  n && events[idx][0] == day) {
                pq.push(events[idx][1]); //push the end day//
                idx++;
            }

            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }



            day++;

            while (!pq.empty() && pq.top() < day) {
                pq.pop(); //remove the expired day//
            }

        }

        return cnt;

    }
};