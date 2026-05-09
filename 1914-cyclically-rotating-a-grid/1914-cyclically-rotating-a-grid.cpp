class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

    int m = grid.size() , n = grid[0].size(); 

    int newk = 0;
    
    int srow = 0 , scol = 0 , erow = m-1 , ecol = n-1;
    
        while (srow < erow && scol < ecol) { //coz no. of rows and columns are even//
        vector<int> temp;

        //first layer//
        for (int i=ecol; i>=scol; i--) {

            temp.push_back(grid[srow][i]);

        }

        //second layer//

        for (int i=srow+1; i<=erow; i++) {

            temp.push_back(grid[i][scol]);
        }

        //third layer//

        for (int i=scol+1; i<=ecol; i++){

            temp.push_back(grid[erow][i]);

        }

        //fourth layer//

        for (int i=erow-1; i>=srow+1; i--) {

            temp.push_back(grid[i][ecol]);

        }

        newk = k%(temp.size());

        cout <<"layer : " << srow << " " << k;

        //reversing the grid//

        reverse(temp.begin() , temp.end());
        reverse(temp.begin() , temp.begin()+newk);
        reverse(temp.begin()+newk , temp.end());

        //reassign it//
        int idx=0;
        //first layer//
        for (int i=ecol; i>=scol; i--) {

        
            grid[srow][i] = temp[idx++];

        }

        //second layer//

        for (int i=srow+1; i<=erow; i++) {

          
            grid[i][scol] = temp[idx++];
        }

        //third layer//

        for (int i=scol+1; i<=ecol; i++){

         
            grid[erow][i] = temp[idx++];

        }

        //fourth layer//

        for (int i=erow-1; i>=srow+1; i--) {

        
            grid[i][ecol] = temp[idx++];

        }

        srow++ , scol++ , erow-- , ecol --;

        }

        return grid;

    }
};