class Solution {
public:

    bool solver(int start , vector<int>&arr , vector<int>&vis) {

        if (start < 0 || start >= arr.size() || vis[start]) return false;
        if (start > -1 &&  start < arr.size()) vis[start] = true;
        if (arr[start] == 0) return true;

        return (solver(start-arr[start] , arr , vis) || solver(start+arr[start] , arr , vis));

    }

    bool canReach(vector<int>& arr, int start) {
        
        vector<int> vis(arr.size());
        return solver(start , arr , vis);

    }
};