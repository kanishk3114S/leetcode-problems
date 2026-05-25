#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        
        int n = s.length();
        //i + minJump <= j <= min(i + maxJump, s.length - 1), and s[j] == '0'.//
        //mn=2 , mx =3;

        //0......2....to.....3.....//

        queue<int>q;
        q.push(0);
        
        vector<bool> hash(n);
        hash[0] = true;

        int farthest = 0;
        
        while (!q.empty()) {

            int size = q.size();

            for (int idx=0; idx<size; idx++) {

                int i = q.front();
                q.pop();

                // if (i == n-1) return true;

                int mini = max(i+mn , farthest+1);
                int maxi = min(i+mx , n-1);

                // cout << mini << " " << maxi;

                for (int id=mini; id<=maxi; id++) {

                    if (s[id] == '0') {

                        if (id == n-1) return true;

                        if (!hash[id]) {
                            q.push(id);
                            hash[id] = true;
                        }
                    }

                }

                farthest = maxi;


            }


        }


        return false;


    }
};
