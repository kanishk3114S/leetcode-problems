class Solution {
public:
    int findMinDifference(vector<string>& time) {
        
        vector<int> minutes;

        //in 1440 mintue zone//

        for (int i=0; i<time.size(); i++) {

            string s = time[i];

            // cout << i << " ";

            string temp = "";
            double res = 0;

            for (char ch:s) {

                if (ch == ':') {
                    res += (stoi(temp)*60);
                    temp = "";
                    // cout << temp << " " << res << endl;
                } else temp += ch;               

            }
            if (temp != "") res += stoi(temp);
            minutes.push_back((int)res);

            // cout << res << " ";

        }

        sort(minutes.begin() , minutes.end());

        int mintime = INT_MAX , t = 0;

        for (int i=0; i<minutes.size()-1; i++) {

            int first = minutes[i];
            int second = minutes[i+1];

            t = min(abs(second - first) , 1440-abs(second-first));
            // cout << second - first <<  " " << 1440-second-first;

            mintime = min(mintime , t);
        }

        mintime = min(mintime , 1440-abs(minutes[minutes.size()-1]-minutes[0]));

        return mintime;

    }
};