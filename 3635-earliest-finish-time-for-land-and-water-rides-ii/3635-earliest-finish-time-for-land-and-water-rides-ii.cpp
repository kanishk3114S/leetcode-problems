
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        vector<pair<int,int>> land,water;

        for (int i=0; i<landStartTime.size(); i++) {

            land.push_back({landStartTime[i] , landDuration[i]+landStartTime[i]});

        }

        for (int i=0; i<waterStartTime.size(); i++) {

            water.push_back({waterStartTime[i] , waterDuration[i]+waterStartTime[i]});

        }

        auto cmp = [](const pair<int,int>&a , const pair<int,int>&b) {

            return a.second < b.second;

        };

        sort(land.begin() , land.end());
        sort(water.begin() , water.end());

        int deadline = INT_MAX;

        for (int i=0; i<land.size(); i++) {

            deadline = min(land[i].second , deadline);

        }

        int cnt1 = INT_MAX , cnt2 = INT_MAX;

        for (int i=0; i<water.size(); i++) {

            if (water[i].first <= deadline) {

                cnt1 = min(cnt1 , deadline+water[i].second-water[i].first);

            } else {
                cnt1 = min(cnt1 , water[i].second);
            }

        }


//..............................................................................................//


        int deadline2 = INT_MAX;

        for (int i=0; i<water.size(); i++) {

            deadline2 = min(water[i].second , deadline2);

        }

        // cout << deadline2;

        for (int i=0; i<land.size(); i++) {

            if (land[i].first <= deadline2) {

                cnt2 = min(cnt2 , deadline2+land[i].second-land[i].first);

            } else {
                cnt2 = min(cnt2 , land[i].second);
            }

        }


        return min(cnt1 , cnt2);



        
    }
};