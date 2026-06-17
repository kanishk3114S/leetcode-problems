class Solution {
public:

    void dfs(vector<int> adj[] ,vector<int>&sz, int node) {

        sz[node] = 1;

        for (auto it:adj[node]) {
            dfs(adj , sz , it);
            sz[node] += sz[it];
        }
    }

    int countHighestScoreNodes(vector<int>& parents) {
        
        int V = parents.size();

        vector<int> adj[V];
        vector<int> sz(V,-1);

        for (int i=0; i<parents.size(); i++) {

            //i --> children , parent[i]---> parent//

           if (parents[i] != -1){
             adj[parents[i]].push_back(i);
           }

        }

        dfs(adj,sz,0);

        long long ans = 0;
        int freq = 0 , maxfreq = 0;

        for (int i=0; i<sz.size(); i++) {
        long long score = 1;

            for (auto it:adj[i]) {
                score*=sz[it];
            }

            cout << score << " ";

            long long rem = sz[0]-sz[i];
            cout << rem <<" ";
            if (rem>0) {
                score*=rem;
            }

            cout << score << endl;

            if (score > ans) {
                freq = 1;
            } else if (score == ans) {
                freq++;
            }

            ans = max(ans , score);

            // cout << score << endl;

        }
        

        return (int)freq;

    }
};