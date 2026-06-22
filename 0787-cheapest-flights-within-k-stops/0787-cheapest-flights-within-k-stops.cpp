class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //same dijkstra with the modified states//

        vector<pair<int,int>> adj[V];

        for (int i=0; i<flights.size(); i++) {

            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        //storing the cost,stops,node//
        using ppp = pair<int,pair<int,int>>;
        priority_queue<ppp,vector<ppp>,greater<ppp>> pq;
        vector<vector<int>> dist(V , vector<int>(k+2 , INT_MAX));

        pq.push({0 , {src , 0}});
        dist[src][0] = 0;

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second.first;
            int currK = pq.top().second.second;
            pq.pop();

            if (node == dst) return d;

            if (d > dist[node][currK]) continue; //remove the stale states//

            for (int i=0; i<adj[node].size(); i++) {

                int nbr = adj[node][i].first;
                int newDist = adj[node][i].second;

                if (currK+1 > k+1) break; //we will allow k+1 if its more than that then break//

                if (d+newDist < dist[nbr][currK+1]) {
                    dist[nbr][currK+1] = d+newDist;
                    pq.push({d+newDist , { nbr , currK+1}});
                }

            }



        }

        return -1;

    }
};