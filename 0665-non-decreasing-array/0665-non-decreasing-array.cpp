class Solution {
public:

    bool check(vector<int>&arr , int idx , int v) {

        // int temp = arr[idx];
        // arr[idx] = val;

        for (int i=1; i<arr.size(); i++){

            int val = arr[i];
            int prev = arr[i-1];
            if (i==idx) val=v;
            if (i-1 == idx) prev = v;

            if (prev > val) return false;

        }

        return true;

    }

    bool checkPossibility(vector<int>& arr) {
        
        int below = 0;
        int p = 0;

        if (arr.size() == 1) return true;

        for (int i=1; i<arr.size(); i++) {

            if (arr[i] < arr[i-1]) {below++; p = i;}

        }

        cout << p << endl;

        if (below >=2) return false;
        else if (below == 1) {

            if (p == arr.size()-1) return true;
            
            if (check(arr , p , min(arr[p+1] , arr[p-1])) || check(arr , p-1 , arr[p])) return true;
            else return false;

        }

        return true;

    }
};