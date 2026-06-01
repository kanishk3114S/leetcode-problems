class Solution {
public:
    int minimumCost(vector<int>& arr) {
        

        int cost = 0;

        if (true) {
        
        sort(arr.rbegin() , arr.rend());

            for (int i=0; i<arr.size(); i++) {

                if ((i+1)%3 == 0) continue;

                cost += arr[i];
            }

            return cost;

        }

        return 0;

    }
};