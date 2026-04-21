class Solution {
public:
    vector<int> parent;

    int finddistance(vector<int>&idx , vector<int>&source , vector<int>&target) {

        unordered_map<int,int>map1;

        int ans = 0;

        for (int i=0; i<idx.size(); i++) {

            map1[source[idx[i]]]++;
        
        }

        for (int i=0; i<idx.size(); i++) {

            int index = idx[i];

            map1[target[index]]--;

        }

        for (auto it:map1){
            ans+= abs(it.second);
        }

        return ans/2;

    }

    int find(int x) {

        if (parent[x] == x) return x;

        return find(parent[x]);

    }

    void dsu(vector<vector<int>>& allowedSwaps , int n) {

        parent.resize(n);
        for (int i=0;i<n;i++) parent[i]=i;

        for (int i=0; i<allowedSwaps.size(); i++) {

            int a = allowedSwaps[i][0];
            int b = allowedSwaps[i][1];

            parent[find(a)] = find(b);

        }

    }
  
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        dsu(allowedSwaps , source.size());
        unordered_map<int,vector<int>> mpp;

        for (int i=0; i<parent.size(); i++) {

            mpp[find(i)].push_back(i); //group the similar indexes//

        }

        int ans = 0;

        for (auto it:mpp) {

            //first vector --> it.second//
            //second vector-->target//

            ans+= finddistance(it.second , source , target);

        }

        return ans;

    }
};