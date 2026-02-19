class Solution {
public:
    int maxVowels(string t, int k) {
        unordered_set<char> s {'a','e','i','o','u'};

        int l = 0 , r = k-1;
        int vowels = 0 , maxvowels = 0;

        for (int i=l; i<=r; i++) {
            if (s.find(t[i]) != s.end()) {
                vowels++;
            }
        }

        maxvowels = vowels;

        while (r < t.length()) {

            l++;
            r++;

            if (r==t.length()) break;

            if (s.find(t[l-1]) != s.end() && s.find(t[r]) == s.end()) {
                vowels--;
            } else if (s.find(t[l-1]) == s.end() && s.find(t[r]) != s.end()) {
                vowels++;
            }

            maxvowels = max(vowels , maxvowels);

        }

    return maxvowels;

    }
};