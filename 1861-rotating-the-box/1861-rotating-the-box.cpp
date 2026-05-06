class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        //move the stones to the right//

        for (int i=0; i<box.size(); i++) {

            int vacate = box[0].size()-1; 

            for (int j=box[0].size()-1; j>-1; j--) {
                //start traversing from the left..and keep a empty pointer to fill the stones//

                // cout << "row no : " << i << endl;

                if (box[i][j] == '#') {

                    box[i][j] = '.'; //empty it
                    box[i][vacate] = '#';
                    vacate--;

                } else if (box[i][j] == '*') {

                    //in case of a obstacle we reset it//

                    vacate = j-1;

                }

            }

        }


        vector<vector<char>> ans(box[0].size() , vector<char>(box.size()));

        for (int i=0; i<box.size(); i++) {

            for (int j=0; j<box[0].size(); j++) {

            ans[j][box.size()-1-i] = box[i][j];

            }

        }

        return ans;

    }
};