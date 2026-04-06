class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obstacles) {
        // maintain a set for the obtacles//

        set<pair<int,int>> s;

        for (auto&o:obstacles) s.insert({o[0] , o[1]});

        vector<pair<int,int>> dir = {

            {0,1} , //north
            {1 , 0}, //east
            {0 , -1}, //south 
            {-1 , 0} //west

        };

        //we will follow a structred simulation...earlier i was jumping to obtacles...but lets move one by one as obtacles is the point not the range//
        int d = 0; //index for the directions....initially it was 0//
        int x = 0 , y = 0; //absolute positions//
        int ans = 0;
        for (int i=0; i<cmd.size(); i++) {

            if (cmd[i] == -1) {
                d = (d+1)%4; //shift right
            } else if (cmd[i] == -2) {
                d = (d+3)%4; //shift left
            } else {

                for (int steps = 0; steps < cmd[i]; steps++) {

                    x+= dir[d].first;
                    y += dir[d].second;

                    if (s.count({x , y})) {

                        x-= dir[d].first;
                        y-= dir[d].second;
                        ans = max(ans , x*x + y*y);
                        break;

                    }

                    ans = max(ans , x*x+y*y);

                }

            }

        }

    return ans;

    }
};