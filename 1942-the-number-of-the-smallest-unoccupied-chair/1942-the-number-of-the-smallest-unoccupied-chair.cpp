class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        unordered_map<int,int> intime;
        unordered_map<int,vector<int>> outime;
        unordered_map<int,int> occupies;
        set<int>s;

        for (int i=0; i<times.size(); i++) {
            s.insert(i);
        }

        int reqtime = 0;

        for (int i=0; i<times.size(); i++) {

            if (i == targetFriend) {
                reqtime = times[i][0];
            }

            intime[times[i][0]]=i;
            outime[times[i][1]].push_back({i});

        }

        for (int time = 1; time<=reqtime; time++) {

            if (outime.count(time)) {

                for (int i=0; i<outime[time].size(); i++) {

                    int id = outime[time][i];
                    int seat = occupies[id];
                    s.insert(seat);
                    occupies.erase(id);
                }
            }

            if (intime.count(time)) {

                occupies[intime[time]] = *s.begin();
                s.erase(s.begin());

            }

        }

        return occupies[targetFriend];


    }
};