class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int total = moves.length();
        unordered_map<char,int> mpp;
        for (int i=0; i<moves.length(); i++) {
            if (moves[i] == 'L' or moves[i] == 'R') mpp[moves[i]]++;
        }

        int diff = 0;
        diff = abs(mpp['L']-mpp['R']);

        return total-mpp['L']-mpp['R']+diff;

    }
};