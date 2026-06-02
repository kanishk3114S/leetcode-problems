class Solution {
public:
    int earliestFinishTime(vector<int>& land_start, vector<int>& land_d, vector<int>& water_start, vector<int>& water_d) {

        int best_d = INT_MAX;
        int rstart = -1 , rend = -1;


        for (int i=0; i<land_start.size(); i++) {

            int start = land_start[i];
            int end = land_start[i] + land_d[i];

            for (int j=0; j<water_start.size(); j++) {

                 rstart = water_start[j];
                 rend = water_start[j]+water_d[j];

                if (rstart <= end) {
                    best_d = min(best_d , end+water_d[j]);
                } else if (rstart > end) {

                    best_d = min(best_d , rend);

                }

            }

            // cout << " start : " << start << " end : " << end <<  " rstart : " << rstart << " rend : " <<  rend << " best_D = " << best_d<<endl;

        }

        for (int i=0; i<water_start.size(); i++) {

            int start = water_start[i];
            int end = water_start[i] + water_d[i];

            for (int j=0; j<land_start.size(); j++) {

                 rstart = land_start[j];
                 rend = land_start[j]+land_d[j];

                if (rstart <= end) {
                    best_d = min(best_d , end+land_d[j]);
                } else if (rstart > end) {

                    best_d = min(best_d , rend);

                }

            }

            // cout << " start : " << start << " end : " << end <<  " rstart : " << rstart << " rend : " <<  rend << " best_D = " << best_d<<endl;

        }

        return best_d;
        
    }
};