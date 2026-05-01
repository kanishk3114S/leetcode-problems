#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solver(vector<int>& arr , int x , int& ans , int f_zero , int totalsum , int n) { //x == no of times the rotation took place//

        if (x == 0) return f_zero;

        int next = solver(arr,x-1,ans,f_zero,totalsum,n) + totalsum - (n * arr[n-x]);

        ans = max(ans , next);

        return next;

    }

    int maxRotateFunction(vector<int>& arr) {
        int f_zero = 0;
        int totalsum = 0;
        int n = arr.size();
        for (int i=0; i<arr.size(); i++) {

            f_zero += i*arr[i];
            totalsum += arr[i];

        }

        int ans = f_zero;

        solver(arr,n-1,ans,f_zero,totalsum,n);

        return ans==INT_MIN ? 0 : ans;

    }
};