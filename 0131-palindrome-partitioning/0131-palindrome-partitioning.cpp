class Solution {
    vector<string> temp;
    vector<vector<string>> ans;
public:

        bool isPalindrome(string s) {

            int start = 0 , end = s.length()-1;

            while (start <= end) {

                if (s[start] == s[end]) {
                    start++;
                    end--;
                } else {
                    return false;
                }
            }
                return true;
        }


    void solver(string s) {

        if (s.length() == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<s.length(); i++) {

            if (s.length() == 0) {
                ans.push_back(temp);
                return;
            }

            string parts = s.substr(0,i+1);
            if (isPalindrome(parts)) {
                temp.push_back(parts);
                solver(s.substr(i+1));
                temp.pop_back();
            }
        }

    }




    vector<vector<string>> partition(string s) {
        
        solver(s);
        return ans;

        ans.clear();
        temp.clear();

    }
};