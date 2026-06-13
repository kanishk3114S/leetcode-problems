class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int,vector<int>> mpp;
        for (int i=0; i<routes.size(); i++) {

            mpp[i] = routes[i];

        }//bus-->stopss//


        vector<int> vis(routes.size() , false);

        unordered_map<int,vector<int>> r_bus;

        for (int i=0; i<routes.size(); i++) {

            for (int j=0; j<routes[i].size(); j++) {

                r_bus[routes[i][j]].push_back(i);

            }

        }

        queue<int> q;

        if (source == target) return 0;

        //we will push the buses //

        for (auto it:r_bus[source]) {
            q.push(it);
            vis[it] = true;
        }

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                int bus = q.front();
                q.pop();

                for (int i=0; i<mpp[bus].size(); i++) {

                    int route = mpp[bus][i];

                    for (auto it:r_bus[route]) {

                        if (!vis[it]) {
                            q.push(it);
                            vis[it] = true;
                        }

                    }

                    if (route == target) return moves+1;


                }

            }

            moves++;


        }

        return -1;


    }
};