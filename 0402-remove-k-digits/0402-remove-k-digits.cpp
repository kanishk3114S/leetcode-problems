class Solution {
public:
    string removeKdigits(string num, int k) {
        
        //if next smaller is withing the //

        vector<int> nextsmaller(num.length());
        // cout << nextsmaller.size() << endl;
        vector<int> vec;
        for (char ch:num){
            vec.push_back(ch-'0');
        }
        // cout << vec.size() <<  endl;
        stack<int> s;

        for (int i=num.length()-1; i>-1; i--) {

            if (s.empty()) {
                nextsmaller[i] = -1;
            } else {

                if (vec[i] > vec[s.top()]) {
                    nextsmaller[i] = s.top();
                } else {
                    while (!s.empty() && vec[i] <= vec[s.top()]) {
                        s.pop();
                    }
                    if (s.empty()) {
                        nextsmaller[i] = -1;
                    } else {
                        nextsmaller[i] = s.top();
                    }
                }

            }
            s.push(i);
        }

        // for (int i=0; i<nextsmaller.size(); i++) {
        //     cout << nextsmaller[i] << " ";
        // }

        string ans = "";
        int temp = k;
        int taken = num.length()-k;
        int diff = -1;

        for (int i=0; i<nextsmaller.size(); i++) {

            if (nextsmaller[i] == -1 && taken > 0) {
                taken--;
                ans += num[i];
            } else {

                diff = nextsmaller[i]-i;
                if (diff <= temp) {
                    temp--;
                    continue;
                } else {
                    ans += num[i];
                    taken--;
                }
            }

            if (taken == 0) break;

        }

        for (int i=0; i<ans.length(); i++){
            if (ans.length() == 1) break;

            if (ans[i]!='0') break;
            else {
                ans.erase(ans.begin()+i);
                i--;
            }
        }

        return ans=="" ? "0"  : ans;

    }
};