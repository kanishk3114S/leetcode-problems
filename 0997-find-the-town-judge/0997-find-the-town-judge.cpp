class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        
        vector<int> trust(n+1,0);
        vector<int> trusted(n+1,0);

        for (int i=0; i<t.size(); i++) {

            int a = t[i][0];
            int b = t[i][1];

            trust[a]++;
            trusted[b]++;

        }

        for (int i=1; i<n+1; i++) {

            if (trust[i] == 0 && trusted[i] == n-1) return i;

        }

        return -1;

    }
};