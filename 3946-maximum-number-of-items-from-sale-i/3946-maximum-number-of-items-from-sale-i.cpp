class Solution {
public:

    int solver(vector<vector<int>>& items,
               vector<int>& freebies,
               int idx,
               int curr_budget,
               vector<vector<int>>& mpp) {

        if (idx == items.size()) {
            return curr_budget / items[0][1];
        }

        if (mpp[idx][curr_budget] != -1)
            return mpp[idx][curr_budget];

        int skip_item = solver(items, freebies, idx + 1, curr_budget, mpp);

        int pick_item = 0;
        if (curr_budget >= items[idx][1]) {
            pick_item = freebies[idx] + 1 +
                        solver(items,
                               freebies,
                               idx + 1,
                               curr_budget - items[idx][1],
                               mpp);
        }

        return mpp[idx][curr_budget] = max(skip_item, pick_item);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> freebies;

        for (int i = 0; i < items.size(); i++) {

            int cnt = 0;

            for (int j = 0; j < items.size(); j++) {

                if (i != j) {

                    int factor_i = items[i][0];
                    int factor_j = items[j][0];

                    if (factor_j % factor_i == 0) {
                        cnt++;
                    }
                }
            }

            freebies.push_back(cnt);
        }

        int b = budget;

        vector<vector<int>> mpp(
            items.size(),
            vector<int>(b + 1, -1)
        );

        return solver(items, freebies, 0, b, mpp);
    }
};