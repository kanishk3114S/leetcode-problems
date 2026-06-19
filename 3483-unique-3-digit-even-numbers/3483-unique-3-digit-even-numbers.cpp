class Solution {

public:

    void solver(vector<int>& digits , vector<bool>&vis , int cnt , unordered_set<int>&s , int temp) {

        if (cnt == 3) {

            if (temp >=100 && temp%2 == 0) {
                s.insert(temp);
            } 

            return;

        }

        for (int i=0; i<digits.size(); i++) {

            if (cnt == 0 && digits[i] == 0) continue;

            if (vis[i]) continue;

            vis[i] = true;
            int next_temp = temp; //save the state//

            if (cnt == 0) {
                next_temp += digits[i]*100;
            } else if (cnt == 1) {
                next_temp += digits[i]*10;
            } else if (cnt == 2) {
                next_temp += digits[i];
            }

            solver(digits,vis,cnt+1,s,next_temp);

            vis[i] = false;
            

        }

    }

    int totalNumbers(vector<int>& digits) {

        unordered_set<int> s;
        vector<bool> vis(digits.size() , false);
        solver(digits,vis,0,s,0);

        // for (auto it:s) {
        //     cout << it << endl;
        // }

        return s.size();
        
    }
};