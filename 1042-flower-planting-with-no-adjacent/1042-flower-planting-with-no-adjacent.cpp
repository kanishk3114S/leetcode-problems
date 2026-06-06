class Solution {
public:

    void dfs(vector<int> adj[] , vector<bool>&vis , vector<int>&color ,  int node) {

        vis[node] = true;
        vector<bool> used(5 , false); //this will check how many colors have been used //

        for (int i=0; i<adj[node].size(); i++) {
            used[color[adj[node][i]]] = true;
        }

        for (int i=1; i<used.size(); i++) {
            if (!used[i])  {
                color[node] = i;
                break;
            }
        }

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];

            if (!vis[nbr]) {
                dfs(adj , vis , color , nbr);

            }


        }

    }


    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<int> adj[n+1];
        vector<bool> vis(n+1 , false);
        vector<int> color(n+1 , 0);


        for (int i=0; i<paths.size(); i++) {

            int u = paths[i][0];
            int v = paths[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);


        }

        for (int i=1; i<vis.size(); i++) {

            if (!vis[i]) dfs(adj , vis , color , i);

        }

        // cout << adj[0].size();

        color.erase(color.begin());

        return color;

    }
};