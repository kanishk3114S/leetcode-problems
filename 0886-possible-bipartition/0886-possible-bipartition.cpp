class Solution {
public:

    bool dfs(vector<int> adj[] , vector<int>&vis , int node , bool color) {

        if (color) {
            vis[node] = 1;
        } else vis[node] = 0;

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];

            if (vis[nbr] == -1) { //not colored
                if (!dfs(adj,vis,nbr, !color)) return false;
            } else if (vis[nbr] != -1  && vis[nbr] == color) return false;

        }

        return true;

    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        //IF THERE IS A CYCLE THEN false else true//??
        vector<int> adj[n];
        vector<int> vis(n,-1);

        for (int i=0; i<dislikes.size(); i++) {

            int u = dislikes[i][0]-1;
            int v = dislikes[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        for (int i=0; i<vis.size(); i++) {
            if (vis[i] == -1) {
                if (!dfs(adj,vis,i,true)) return false;
            }
        }

        return true;

    }
};