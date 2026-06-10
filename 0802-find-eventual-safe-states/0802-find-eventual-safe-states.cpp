#include<bits/stdc++.h>
using namespace std;


//Khan Algo --> when we use topological sort using the BFS //

// we maintain a 1) indegree[node] 2) we try to insert the elements in the answer when the indegree becomes 0//

// indegree=0 (means no node is before that node so put that node in the answer earlier)//


class Solution {
  public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        // Khan's---> BFS+indegree//

        int V = graph.size();
        int n = graph.size();

        vector<int> indegree(V,0);
        vector<int> adj[V];

        for (int i=0; i<n; i++) {
            for (int j=0; j<graph[i].size(); j++) {

                adj[graph[i][j]].push_back(i);

            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<graph[i].size(); j++) {
                indegree[i]++;
            }
        }

        //push all the nodes with indegree = 0 into the queue (coz they will be the first element)//

        queue<int> q;

        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;


        while(!q.empty()) {

            int size = q.size();
            for (int i=0; i<size; i++) {

                int node = q.front();
                q.pop();

                for (int i=0; i<adj[node].size(); i++) {

                    int nbr = adj[node][i];
                    indegree[nbr]--;

                    if(indegree[nbr] == 0) {
                        q.push(nbr);
                    }

                }

                ans.push_back(node);

            }

        }

        sort(ans.begin(), ans.end());

        return ans;

    }
};