class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& asteroid) {
        sort(asteroid.begin() , asteroid.end());

        long long mass = m;

        for (int i=0; i<asteroid.size(); i++) {

            if (mass < asteroid[i]) return false;

            mass+= asteroid[i];

        }

        return true;

    }
};