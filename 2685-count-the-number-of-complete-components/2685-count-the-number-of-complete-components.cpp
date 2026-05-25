#include <bits/stdc++.h>
using namespace std;



//detect a cycle in bfs//
//if a (canvisit)node is already visited...then true else false//

class Solution {
  public:

    void bfs(vector<int> adj[] , vector<bool>&vis , int source , int&edges , int&n) {
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {

            int size = q.size();

            for (int id=0; id<size; id++) {

                int node = q.front();
                n++;
                q.pop();
                

                for (int i=0; i<adj[node].size(); i++) {

                    if (!vis[adj[node][i]]) {
                        q.push(adj[node][i]);
                        vis[adj[node][i]]=true;
                    }


                }
                    edges += adj[node].size();
            }

        }
    }

    int countCompleteComponents(int V, vector<vector<int>>& edge) {
        // Code here
        

        vector<int> adj[V];
        vector<bool> vis(V,false);

        for (int i=0; i<edge.size(); i++) {

            int u = edge[i][0];
            int v = edge[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        int n = 0;
        int cnt = 0;
        int edges = 0;

        for (int i=0; i<vis.size(); i++) {

            if (!vis[i]) {
            bfs(adj , vis , i , edges, n);
            edges/=2;
            if (edges == (n*(n-1))/2) cnt++;
            else if (n == 1 || n == 2) cnt++;
            edges = 0;
            n = 0;
            }

        }

        return cnt;



    }
};