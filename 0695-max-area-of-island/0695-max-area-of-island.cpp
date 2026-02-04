class Solution {
public:
    int rows , cols;

    int dfs(vector<vector<int>> &grid, int r , int c){
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;

        int area = 1;
        area += dfs(grid , r +1 , c);
        area += dfs(grid , r -1 , c);
        area += dfs(grid , r , c + 1);
        area += dfs(grid , r ,c -1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 1){
                    maxArea = max(maxArea , dfs(grid , i ,j));
                }
            }
        }
        return maxArea;
    }
};