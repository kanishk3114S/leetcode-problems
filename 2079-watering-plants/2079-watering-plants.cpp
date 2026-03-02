class Solution {
public:
    int wateringPlants(vector<int>& arr, int capacity) {
        

        int storage = capacity;
        int steps = 0;

        for (int i=0; i<arr.size(); i++) {

            steps++;
            if (arr[i] <= storage) {
                storage -= arr[i]; //watered it//
            } else {
                steps--;
                steps += (2*i)+1;
                storage = capacity; //refilled//
                storage -= arr[i];
            }

            // cout << steps << " ";

        }

        return steps;

    }
};