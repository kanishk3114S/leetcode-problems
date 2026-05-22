class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color , vector<vector<bool>>&vis,int og){

        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != og || vis[sr][sc]) return;

        if (image[sr][sc] == og) {
            vis[sr][sc]=true;
            image[sr][sc] = color;
        }

        dfs(image , sr+1 , sc , color , vis , og);
        dfs(image , sr , sc+1 , color , vis , og);
        dfs(image , sr-1 , sc , color , vis , og);
        dfs(image , sr , sc-1 , color , vis , og);



    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        vector<vector<bool>> vis(image.size() , vector<bool>(image[0].size() , false));
        dfs(image,sr,sc,color,vis,og);
        return image;
    }
};