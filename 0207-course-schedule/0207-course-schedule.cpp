class Solution {
public:

    bool iscycle(vector<int> adj[] , vector<bool>&newvis , vector<bool>&pathvis , int node) {

        newvis[node] = true;
        pathvis[node] = true;

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];

            if (newvis[nbr] && pathvis[nbr]) return true;
            if (!newvis[nbr]) {

                if (iscycle(adj,newvis,pathvis,nbr)) return true;

            }

        }

        pathvis[node] = false;
        return false;

    }




    bool canFinish(int V, vector<vector<int>>& edges) {
        // we know we have to find the what occured firat and ordering//
        // that is--> course scheduling./

        vector<bool> vis(V,false);
        vector<bool> newvis = vis;
        vector<bool> pathvis = vis;
        vector<int> adj[V];

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);

        }

        for (int i=0; i<newvis.size(); i++) {

            if (!newvis[i]) {
                if(iscycle(adj,newvis,pathvis,i)) return false;
            }

        }

        return true;

    }
};