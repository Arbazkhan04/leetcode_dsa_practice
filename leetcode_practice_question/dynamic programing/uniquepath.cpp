class Solution {
public:
    int uniquePaths(int m, int n) {
       return dp(m-1,n-1);
    }
    int dp(int m,int n){
          if(m+n==0){
            return 1;
        }
        int ways = 0;
        if(m>0){
            ways+=dp(m-1,n);
        }
        if(n>0){
            ways+=dp(m,n-1);
        }
        return ways;
    }
};