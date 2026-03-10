class Solution {
public:
    int minOperations(string s) {
        
    
        string temp = s;
        sort(temp.begin() , temp.end());
        if (temp == s) return 0; //string is already sorted//

        if (s.length() == 2 && temp != s) return -1;

        string c1 = s;
        string c2 = s;
        sort(c1.begin() , c1.end()-1);
        // cout << c1 << endl;
        sort(c2.begin()+1 , c2.end());
        // cout << c2 << endl;

        if (c1 == temp) return 1;
        if (c2 == temp) return 1;

        sort(c1.begin()+1 , c1.end());
        // cout << c1 << endl;
        sort(c2.begin() , c2.end()-1);

        if (c1  == temp) return 2;
        if (c2 == temp) return 2;

        sort(c1.begin() , c1.begin()+2);
        // cout << c1 ;
        sort(c2.end()-2 , c2.end());

        if (c1 == temp || c2 == temp) return 3;

        return -1;

    }
};