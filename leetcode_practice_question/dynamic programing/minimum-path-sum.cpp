class Solution {
public:
    vector<vector<int>> grid;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        this->grid = grid;
        return dp(m,n);
    }
    int dp(int row,int col){
        if(row+col==0){
            return grid[row][col];
        }
        int sum =0;
        int ans=INT_MAX;
        if(row>0){
          ans = min(ans,dp(row-1,col));   
        }
        if(col>0){
             ans = min(ans,dp(row,col-1));
        }
        sum +=grid[row][col]+ans;
        return sum;
    }
};