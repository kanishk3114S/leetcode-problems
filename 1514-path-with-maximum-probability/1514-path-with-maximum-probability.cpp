class Solution {
public:
    double maxProbability(int V, vector<vector<int>>& edges, vector<double>& P, int src , int dest) {
        
        vector<pair<int,double>> adj[V];

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double edgeWt = P[i];

            adj[u].push_back({v , edgeWt});
            adj[v].push_back({u , edgeWt});

        }

        priority_queue<pair<double,int>> pq;

        vector<double> dist(V , INT_MIN);

        dist[src] = 1;

        pq.push({1.0 , src});

        while (!pq.empty()) {

            double d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == dest) return d;

            for (auto it:adj[node]) {

                int nbr = it.first;
                double wt = it.second;

                if (wt*d > dist[nbr]) {
                    dist[nbr] = wt*d;
                    pq.push({wt*d , nbr});
                }

            }

        }

        return 0;
    }
};