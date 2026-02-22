class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& arr) {
        
        stack<long long> s;
        vector<long long> result;
        long long el = 0;

        for (int i=0; i<arr.size(); i++) {
            if (s.empty()) {
                s.push(arr[i]);
            } else {
                if (arr[i] != s.top()) {
                    s.push(arr[i]);
                } else {
                el = arr[i];
                while (!s.empty() && el == s.top()) {
                    el += s.top();
                    s.pop();
                }
                s.push(el);
             }
            }
        }

        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();


        }

        reverse(result.begin() , result.end());
        return result;


        


    }
};