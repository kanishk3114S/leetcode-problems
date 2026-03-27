class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& addoninterval) {
        
        intervals.push_back(addoninterval);

        auto cmp = [](const vector<int>&a , const vector<int>&b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };

        sort(intervals.begin() , intervals.end() , cmp); 

        vector<vector<int>> result;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i=1; i<intervals.size(); i++) {

            if (intervals[i][0] <= end) {
                end = max(end , intervals[i][1]);
            } else {

                result.push_back({start , end});
                start = intervals[i][0];
                end = intervals[i][1];

            }

        }

        result.push_back({start , end});

        return result;

    }
};