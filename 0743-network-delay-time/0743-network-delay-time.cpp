class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
              vector<pair<int,int>> adj[V+1];

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            int edgeWt = edges[i][2];

            adj[u].push_back({v , edgeWt});
        }

        set<pair<int,int>> pq;

        vector<int> dist(V+1 , INT_MAX);

        dist[0] = -1;
        dist[src] = 0;

        pq.insert({0 , src});

        while (!pq.empty()) {

            int d = pq.begin()->first;
            int node = pq.begin()->second;
            pq.erase({d , node});

            for (auto it:adj[node]) {

                int nbr = it.first;
                int wt = it.second;

                if (wt+d < dist[nbr]) {

                    if (pq.count({dist[nbr] , nbr})) {
                        pq.erase({dist[nbr] , nbr});
                    }

                    dist[nbr] = wt+d;
                    pq.insert({wt+d , nbr});
                }

            }

        }

       int ans = 0;

       for (auto it:dist) {
        ans = max(it , ans);
        if (it == INT_MAX) return -1;
       }

       return ans;  
    }
};