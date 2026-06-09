class Solution {
public:

    void dfs(vector<int> adj[] , vector<bool>&vis , int node , stack<int>&s) {

        vis[node] = true;

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];

            if (!vis[nbr]) {

                dfs(adj,vis,nbr,s);

            }


        }


        s.push(node);

    }

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




    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        // we know we have to find the what occured firat and ordering//
        // that is--> course scheduling./

        vector<bool> vis(V,false);
        vector<bool> newvis = vis;
        vector<bool> pathvis = vis;
        vector<int> adj[V];
        stack<int> s;
        vector<int> ans;


        if (edges.size() == 0) {
            for (int i=0;i<V;i++){
                ans.push_back(i);
            }
            return ans;
        }

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);

        }

        for (int i=0; i<newvis.size(); i++) {

            if (!newvis[i]) {
                if(iscycle(adj,newvis,pathvis,i)) return {};
            }

        }

        for (int i=0; i<V; i++) {

            if (!vis[i]) {
                dfs(adj,vis,i,s);
            }

        }

        while(!s.empty()) {

            ans.push_back(s.top());

            s.pop();

        }

        return ans;

    }
};