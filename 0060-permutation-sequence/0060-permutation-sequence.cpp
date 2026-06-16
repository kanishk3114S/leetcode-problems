class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> arr;

       for (int i=1; i<=n; i++) {
        arr.push_back(i);
       }

        int i=0;
       while (i < k-1) {
        next_permutation(arr.begin() , arr.end());
        i++;
       }

       string ans = "";
       for (auto it:arr) {
        ans += to_string(it);
       }

       return ans;

    }
};