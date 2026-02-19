class Solution {
public:
    int countBinarySubstrings(string s) {

    char cand = 0;
    int streak = 0;
    vector<int> result;
        
     for(int i=0; i<s.length(); i++) {

      cand = s[i];

         while (s[i]==cand) {
             streak++;
             i++;
         }

         result.push_back(streak);
         streak=0;

         i--;       
         
     }

       

        int ans = 0;

    for(int i=0; i<result.size()-1; i++) {
        ans+= min(result[i] , result[i+1]);
    }
        return ans;
    }
};