class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        
        vector<int> shifts;

        if (s==t) return true;
        if (s.length() != t.length()) return false;

        for (int i=0; i<s.length(); i++) {

            if (s[i] != t[i]) {
                int diff = ((t[i]-'0') - (s[i]-'0') + 26)%26;

                // cout << t[i] << " " << s[i] << " diff : " << diff << endl;

                // if (diff < 0) {
                //     diff = 26-diff;
                // }
                shifts.push_back(diff);
            }

        }

        sort(shifts.begin() , shifts.end());

        for (int num:shifts) cout << num << " ";

        // for (int i=0; i<shifts.size(); i++) {



        // }

        if (shifts[0] >  k) return false;

        int cycle = 0;

        for (int i=1; i<shifts.size(); i++) {

            // int el = shifts[i]+(26*cycle);

            // if (el < shifts[i-1]) retu
            int el = shifts[i];
            if (el == shifts[i-1]){
                cycle++;
                el = shifts[i]+(26*cycle); //new el// 
            } else {
                cycle = 0;
            }

            if (el > k || el < shifts[i-1]) return false;

        }

        return true;
    }
};