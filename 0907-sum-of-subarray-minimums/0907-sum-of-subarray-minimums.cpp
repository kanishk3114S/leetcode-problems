#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const long long mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        //every element will be the smaller element for the (n) number of subarrays//

        stack<int> s;
        vector<int> left_min;
        vector<int> right_min;

        //in left//

        for (int i=0; i<arr.size(); i++) {

            if (s.empty()) {

                left_min.push_back(-1);

            } else {

                if (arr[i] > arr[s.top()]) {

                    left_min.push_back(s.top());

                } else {

                    while (!s.empty() && arr[i] < arr[s.top()]) s.pop();

                    if (s.empty()) left_min.push_back(-1);
                    else left_min.push_back(s.top());

                }

            }
            s.push(i);

        }


        //in right//

        while(!s.empty()) s.pop();

        for (int i=arr.size()-1; i>-1; i--) {

            if (s.empty()) {

                right_min.push_back(arr.size());

            } else {

                if (arr[i] > arr[s.top()]) {

                    right_min.push_back(s.top());

                } else {

                    while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();

                    if (s.empty()) right_min.push_back(arr.size());
                    else right_min.push_back(s.top());

                }

            }
            s.push(i);

        }

        reverse(right_min.begin() , right_min.end());
        // for (int i=0; i<right_min.size(); i++) cout << right_min[i] << " ";

        //for every index we have the left min and right min//
        long long sum = 0;
        long long subarr = 0;
        for (int i=0; i<arr.size(); i++) {

            int leftel = i - left_min[i];
            int rightel = right_min[i] - i; //include the ith element only once//

            subarr = leftel*rightel;

            // cout << subarr << " ";
 
            sum = (sum + (subarr)*arr[i])%mod;

        }

        return sum;

    }
};