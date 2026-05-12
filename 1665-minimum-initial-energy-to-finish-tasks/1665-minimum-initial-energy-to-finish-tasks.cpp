#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//question : task[i] = [actual,minimum]; // //actual <= minimum....//
// so we have to complete all the tasks by using minimum initial energy//
// which fullfill every minimum requirement and at the end 1 is left as remaining energy//

//can be solved by sorting...........//
// what we need is to solve every task...i.e energy remains after every task = (min-actual) //
//left over energy is dangerous as its the worst task//
//and if the leftover energy keeps getting add therefore we will use extra energy//

// so to remove the left over energy......do the tasks which require most left over energy..and then keep moving forward//
//eg [[5,10] , [1,9]]// 

// in this example starting from 5,10 is useless coz....after completing of first task we will have 5 left and 10 init....then req 9....therefore add 4.....init=14.....but we drain only 1 .. remainig energy = 8....... which is wrong...14 is not the answer//

//but if we start from 1,9......init=9 and leftover = 8...but the left over will enough to start 2nd task as we need only 2 to add....init = 11.....and maximum energy is consumed....//

//maximum left over is helpful for the upcoming as less to_add is done + remains get so less//

//so do the worst task first//

struct D {
    int a , b , c;
};

    int minimumEffort(vector<vector<int>>& tasks) {
        
        vector<D> v;

        for (int i=0; i<tasks.size(); i++) {

            int diff = tasks[i][1] -  tasks[i][0];

            v.push_back({diff , tasks[i][0] , tasks[i][1]});
        
        }

        sort(v.begin() , v.end() , [](const D a , const D b) {

            // if (a.a == b.a) {

            //     return a.c>b.c;

            // }

            return a.a > b.a;

        });

        for (int i=0; i<v.size(); i++) {

            cout << v[i].a << " " << v[i].b<< " " << v[i].c << endl;

        }

        int init = 0 , curr = 0;

            init = v[0].c;
            curr = v[0].a;
            // cout << init;
        for (int i=1; i<v.size(); i++) {

            // cout << curr << endl;

            if (curr < v[i].c) {
                // cout << "true at : " << curr << " " << v[i].c << endl;
                init += (v[i].c-curr);
                curr = v[i].c;
                curr -= v[i].b;

            } else {

                curr -= v[i].b;

            }

            // cout << init << endl;

        }

        return init;

    }
};