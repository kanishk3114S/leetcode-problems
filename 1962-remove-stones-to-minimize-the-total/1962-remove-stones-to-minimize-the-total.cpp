class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;

        for (int i=0; i<piles.size(); i++) {
            pq.push(piles[i]);
        }

        for (int i=0; i<k; i++) {

            int element = pq.top();
            pq.pop();

            element -= floor(element/2);
            pq.push(element);

        }

        int sum = 0;

        while (!pq.empty()) {

            sum += pq.top();
            pq.pop();

        }

        return sum;

    }
};