class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        using ppi = pair<long double ,pair<int,int>>;
        priority_queue<ppi> pq;

        for (int i=0; i<arr.size()-1; i++) {

            for (int j=i+1; j<arr.size(); j++) {

                long double div = (long double)arr[i]/arr[j];

                pq.push({div , {arr[i] , arr[j]}});

                if (pq.size() > k) {
                    pq.pop();
                }

            }
                
        }

        // while (!pq.empty()) {

        //     cout << pq.top().first << "  : el1 and el2 are : " << pq.top().second.first << " " <<pq.top().second.second << endl;
        //     pq.pop(); 

        // }

        return {pq.top().second.first , pq.top().second.second};

    }
};