class Solution {
public:
    bool judgeCircle(string moves) {
        
        unordered_map<char,int> mpp;

        for (char ch:moves) mpp[ch]++;

        if (mpp['U'] == mpp['D'] && mpp['L'] == mpp['R']) return true;

        return false;

    }
};