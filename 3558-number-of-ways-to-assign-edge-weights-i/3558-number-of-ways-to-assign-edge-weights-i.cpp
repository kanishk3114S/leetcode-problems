class Solution {
public:

    void d(vector<int> adj[] , vector<bool>&vis, int cnt , int&maxcnt , int node) {

        vis[node] = true;
        maxcnt = max(cnt,maxcnt);

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];
            if (!vis[nbr]) {
            d(adj ,  vis , cnt + 1 , maxcnt  , nbr);
            }            
        }

    }

    long long modpow(long long a, long long b) {
    long long ans = 1;
    long long MOD = 1e9 + 7;

    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int> adj[n+2];
        vector<bool> vis(n+2);

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxcnt = INT_MIN;

        d(adj,vis,0,maxcnt,1);
        
        //now we have maxcnt....O(N)//

         //edges---> maxdepth-1//

        long long ans = modpow(2,maxcnt-1);

        return ans;

    }
};