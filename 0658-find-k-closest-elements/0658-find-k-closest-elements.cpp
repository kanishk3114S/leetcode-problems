class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        using pp = pair<int,int>;

        priority_queue<pp> pq;

        for (int i=0; i<arr.size(); i++) {

            int diff = abs(arr[i] - x);

            pq.push({diff , arr[i]});

            if (pq.size() > k) pq.pop();

        }

        vector<int> ans;

        while (!pq.empty()) {

            ans.push_back(pq.top().second);
            pq.pop();
        
        }
        sort(ans.begin() , ans.end());
        return ans;

    }
};