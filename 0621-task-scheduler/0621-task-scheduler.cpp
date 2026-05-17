class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> hash;        
        unordered_map<char,int> mpp;
        for (int i=0; i<tasks.size(); i++) {

            mpp[tasks[i]]++;
            hash[tasks[i]] = 1;

        }

        using pp = pair<int,char>;
        priority_queue<pp> pq;

        for(auto it:mpp) {

            pq.push({it.second , it.first});

        }



        int seat = 1;

        while (!pq.empty()) {

        vector<pp> corner;

        while (!pq.empty()) {

            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            if (hash[ch] <= seat) {
                freq--;
                if (freq > 0) {
                pq.push({freq , ch});    
                }
                hash[ch] = seat+1+n;
                break;
            } else {
                corner.push_back({freq,ch});
            }

        }

        for (int i=0; i<corner.size(); i++) {
            pq.push(corner[i]);
        }
        seat++;
        corner.empty();

        }

        return seat-1;
        

    }
};