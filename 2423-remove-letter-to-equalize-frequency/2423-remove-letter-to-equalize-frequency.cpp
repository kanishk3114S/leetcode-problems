class Solution {
public:
    bool equalFrequency(string word) {

        vector<int> freq(26, 0);

        for (char ch : word) {
            freq[ch - 'a']++;
        }

        unordered_map<int, int> mpp;

        for (int f : freq) {
            if (f) mpp[f]++;
        }

        if (mpp.size() > 2) return false;

        if (mpp.size() == 1) {

            auto it = mpp.begin();

            int freqVal = it->first;
            int count = it->second;

            // a,b,c OR zzz
            if (freqVal == 1) return true;

            // aaa
            if (count == 1) return true;

            return false;
        }

        auto it = mpp.begin();

        int f1 = it->first;
        int c1 = it->second;
        ++it;
        int f2 = it->first;
        int c2 = it->second;

        if (f1 > f2) {
            swap(f1, f2);
            swap(c1, c2);
        }

        // Example: {1:1, 2:3}
        if (f1 == 1 && c1 == 1) return true;

        // Example: {2:3, 3:1}
        if (f2 == f1 + 1 && c2 == 1) return true;

        return false;
    }
};