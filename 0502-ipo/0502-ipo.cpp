class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        using pp = pair<int,int>;
        vector<pp> v;

        for (int i=0; i<profits.size(); i++) {

            v.push_back({capital[i] , profits[i]});
            
        }

        //now we have a v vector in which we will work on//

        sort(v.begin() , v.end());

            struct cmp {

                bool operator()(pair<int,int>& a, pair<int,int>& b) {

                    if (a.second == b.second) {
                        return a.first > b.first;
                    }

                    return a.second < b.second;
                }
            };

        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               cmp> pq;

        int idx = 0;

        //(1,1) (1,2) (2,3)//
        
        for (int i=0; i<k; i++) {

            //for every k first insert the choices in the maxheap//

            while (idx < v.size() && v[idx].first <= w) {

                pq.push(v[idx]);
                idx++;

            } 

            //we got all the choices//

           if (!pq.empty()) {
            w+=pq.top().second;
            pq.pop();
           }

        }

        return w;

    }
};