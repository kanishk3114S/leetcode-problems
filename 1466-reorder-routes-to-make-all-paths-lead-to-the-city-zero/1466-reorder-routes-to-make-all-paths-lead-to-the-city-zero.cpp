class Solution {
public:

    void dfs(vector<vector<pair<int,int>>>& adj , vector<bool>&vis , int&cnt , int node) {

        vis[node] = true;

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i].first;
            int cost = adj[node][i].second;

            if (!vis[nbr]) {
                cnt += cost;
                dfs(adj , vis , cnt , nbr);
            }

        }

    } 

    int minReorder(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n , false);
        vector<vector<pair<int,int>>> adj(n);

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v , 1});
            adj[v].push_back({u , 0});

        }

        int cnt = 0;

        dfs(adj , vis , cnt , 0);

        return cnt;



    }
};