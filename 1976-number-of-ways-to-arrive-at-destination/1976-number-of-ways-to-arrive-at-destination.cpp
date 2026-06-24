#include <bits/stdc++.h>
using namespace std;


//no of ways to reach the destination.....//

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& roads) {
       const long long MOD = 1e9+7;
       
        vector<pair<long long,long long>> adj[V];

        for (long long i=0; i<roads.size(); i++) {

            long long u = (long long)roads[i][0];
            long long v = (long long)roads[i][1];
            long long wt = (long long)roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }


        using pp = pair<long long,long long>;

        priority_queue<pp,vector<pp>,greater<pp>> pq;

        vector<long long> dist(V+1 , 1e18);
        vector<long long> ways(V+1 , 0);

        dist[0] = 0;
        ways[0] = 1; //the no of ways so that u can reach the node 0 is 1//


        pq.push({0 , 0});

        while (!pq.empty()) {

            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();


            if (d > dist[node]) continue; //remove the stale states//

            for (long long i=0; i<adj[node].size(); i++) {

                long long nbr = adj[node][i].first;
                long long wt = adj[node][i].second;

                //first time reaching the node//
                if (wt + d < dist[nbr]) {

                    dist[nbr] = wt+d;
                    ways[nbr] = ways[node];
                    ways[nbr] %= MOD;
                    pq.push({wt+d , nbr});
                } else if (wt+d == dist[nbr]) {

                    ways[nbr] += ways[node]; //add the ways//
                    ways[nbr] = ways[nbr]%MOD;

                }

            }



        }


        return ways[V-1] == 0 ? -1 : ways[V-1];



    }
};



