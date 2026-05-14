class Solution {
public:
    bool isGood(vector<int>& arr) {
        
        int n = arr.size();
        vector<bool> seen(n+1 , false);
        bool found = false;
        for (int i=0; i<arr.size(); i++) {

            if (arr[i] >= n)  return false;
            if (seen[arr[i]]) {
                seen[arr[i]]=false;
            }
            else seen[arr[i]] = true;
            
            if (arr[i] == n-1) found=true;

        }   

        if (seen[n-1] || !found) return false;
        

        // for (int i=1; i<seen.size()-1; i++) {

        //     cout << "indi : " << i << seen[i] ? " yes" : " no";
        //     cout << endl;

        // }

        cout << n-1;

        for (int i=1; i<seen.size()-1; i++) {
            
            if (i!=n-1 && !seen[i]) {return false;} 

        }

        return true;

    }
};