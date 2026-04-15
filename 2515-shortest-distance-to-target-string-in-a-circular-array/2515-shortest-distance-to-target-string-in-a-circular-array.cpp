class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        for (int i=0; i<n; i++) {

            if (words[i] == target) {

                int length = abs(i - startIndex);
                int ring = n - length;

                return min(length , ring);

            }

        }
        return -1;

    }
};