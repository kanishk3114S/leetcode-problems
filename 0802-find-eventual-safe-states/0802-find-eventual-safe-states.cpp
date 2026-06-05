#include <bits/stdc++.h>
using namespace std;

//term node ---> no outgoing edge//
// safe node ---> every path from that node leads to term node//

//observation--> if a node is attached to a cycle || part of a cycle === it is not a safe node//

//while traversing a node if you got a cycle just return; //

class Solution {
public:

    //dfs function..//
    bool dfs(vector<vector<int>>& adj , vector<bool>&vis , vector<bool>&pathvis , int node) {

        vis[node] = true;
        pathvis[node] = true;

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];

            if (nbr == node) return true;
            if (vis[nbr] && pathvis[nbr]) return true;
            else if (!vis[nbr]) {
                if(dfs(adj , vis , pathvis , nbr)) return true;
            }
            

        }

        pathvis[node] = false;
        return false;

    }


    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        
        vector<bool> vis(adj.size() , false);
        vector<bool> pathvis(adj.size() , false);

        vector<int> ans;

        for (int i=0; i<vis.size(); i++) {

            if (!vis[i]) {
                dfs(adj , vis , pathvis , i);
            }

        }

        for (int i=0; i<pathvis.size(); i++) {
            if (!pathvis[i]) ans.push_back(i);
        }

        return ans;

        

    }
};