class Solution {
public:
    long long maxTotal(vector<int>& arr, string s) {
        

        int cnt = 0;
        long long ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

        for (int i=0; i<s.length(); i++) {

            if (s[i] == '1') {
                pq.push(arr[i]);
                if (i>0 && s[i-1] == '0') {
                    pq.push(arr[i-1]);
                }
                cnt++;
            } else {

                if (cnt > 0) {

                    if (pq.size() > cnt) {
                        pq.pop();
                    }
                    while (!pq.empty()) {
                        ans+=pq.top();
                        pq.pop();
                    }

                    cnt = 0;

                }

            }

        }
                if (cnt > 0) {

                    if (pq.size() > cnt) {
                        pq.pop();
                    }
                    while (!pq.empty()) {
                        ans+=pq.top();
                        pq.pop();
                    }

                }

                return ans;

    }
};