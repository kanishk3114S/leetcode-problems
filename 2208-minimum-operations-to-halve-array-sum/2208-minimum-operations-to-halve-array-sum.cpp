class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        double sum = 0;
        priority_queue<double> pq;
        for (int num:nums) {

            sum += num;
            pq.push((double)num);

        }

        int op = 0;
        double temp = sum;

        while (sum > temp/2) {

            double element = pq.top();
            pq.pop();
            element /= 2;
            op++;
            sum = sum-element;
            pq.push(element);
        }

        return op;

    }
};