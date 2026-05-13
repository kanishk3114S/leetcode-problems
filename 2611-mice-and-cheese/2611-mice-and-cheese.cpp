class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {


    vector<pair<int,pair<int,int>>> v;

    for (int i=0; i<r1.size(); i++) {

       int diff = r1[i]-r2[i];
        v.push_back({diff , {r1[i] , r2[i]}});

    }

    sort(v.begin() , v.end() , [](const pair<int,pair<int,int>>&a , const pair<int,pair<int,int>>&b){

        if (a.first == b.first) return a.second.first > b.second.first;
        return a.first > b.first;

    });

    int picked = 0;
    int reward1 = 0;
    int reward2 = 0;
    for (int i=0; i<v.size(); i++) {

        if (picked < k) {
            // cout << k << " first" << endl;
            reward1+=v[i].second.first;
            picked++;
            
        } else {
             reward2+=v[i].second.second;

        }
    }

    return (reward1+reward2);


    }
};