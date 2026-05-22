#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:

    bool dfs(int source , int destination , vector<int> adj[] , vector<bool>&vis) {

        vis[source] = true;
        if (source == destination) return true;

        for (int i=0; i<adj[source].size(); i++) {

            if (!vis[adj[source][i]]) {
                if (dfs(adj[source][i] , destination , adj , vis)) return true;
            }

        }

        return false;

    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        //Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2//
        
        vector<bool> vis(n);
        vector<int> adj[n];

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        
        return dfs(source , destination , adj , vis);

    }
};