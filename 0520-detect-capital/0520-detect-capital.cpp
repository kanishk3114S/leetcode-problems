class Solution {
public:
    bool detectCapitalUse(string words) {
        
        if (islower(words[0])) {

            for (int i=1; i<words.size(); i++) {

                if (!islower(words[i])) return false;

            }

        } else {
            bool lower = false , upper = false;
            for (int i=1; i<words.size(); i++) {

                if (islower(words[i])) lower = true;
                if (!islower(words[i])) upper = true;

            }

            if (lower && upper) return false;

        }

        return true;

    }
};