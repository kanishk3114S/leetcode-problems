class Solution {
public:

    bool check(vector<int>& dist, double hour , int speed) {
        const long double EPS = 1e-12L;
        long double timeTaken = 0;

        for (int i=0; i<dist.size()-1; i++) {

            timeTaken += ((dist[i]+(speed-1))/speed);

            if (timeTaken > hour) return false;

        }

        timeTaken += ((long double)dist.back()/speed);
        // cout << "Timetaken : " << timeTaken << " hours  " << hour << endl;

        return timeTaken <= (long double)hour+EPS;


    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        // int sum = 0;
        // for (auto it:dist) sum+=it;

        int low = 1 , high = 1e7;
        int ans = -1;

        while (low <= high) {

            int mid = low-(low-high)/2;

            if (check(dist,hour,mid)) {
                // cout << "check is true for : " << low << " " << high << " mid : " << mid << endl;
                ans = mid;
                high = mid-1;
            } else {
                // cout << "check is false for : " << low << " " << high << " mid : " << mid << endl;
                low = mid+1;
            }

        }

        return ans;


    }
};