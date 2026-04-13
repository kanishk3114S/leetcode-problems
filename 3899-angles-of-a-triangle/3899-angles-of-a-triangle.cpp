class Solution {
public:

        void getAngles(vector<int>& sides , vector<double>&ans) {
            double a = sides[0], b = sides[1], c = sides[2];
        
            double A = acos((b*b + c*c - a*a) / (2*b*c));
            double B = acos((a*a + c*c - b*b) / (2*a*c));
            double C = acos((a*a + b*b - c*c) / (2*a*b));
        
            // Convert radians to degrees
            A = A * 180.0 / M_PI;
            B = B * 180.0 / M_PI;
            C = C * 180.0 / M_PI;
        
            ans.push_back(A);
            ans.push_back(B);
            ans.push_back(C);

        }
    
    vector<double> internalAngles(vector<int>& sides) {

        bool isPossible = true;
        vector<double> ans;

        int sum = 0;

        for (int val:sides) sum+=val;

        for (int val:sides) {

            int remains = sum - val;

            if (remains <= val) isPossible = false;
            
        }

        if (!isPossible) return ans;

        getAngles(sides , ans);
        sort(ans.begin() , ans.end());
        return ans;

        
        
    }
};