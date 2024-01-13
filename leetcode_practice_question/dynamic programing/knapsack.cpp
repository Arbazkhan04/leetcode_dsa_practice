//memoization method
class knap
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> memo;
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memo=vector<vector<int>>(n+1,vector<int>(W+1,-1));
       return dp(W,wt,val,n);
    }
    int dp(int W,int wt[],int val[],int n)
    {
       if(W==0 || n==0){
           return 0;
       }
       if(memo[n][W]!=-1){
           return memo[n][W];
       }
       else if(wt[n-1]<=W){
          return memo[n][W]= max(val[n-1]+dp(W-wt[n-1],wt,val,n-1),dp(W,wt,val,n-1));
       }
       else{
          return memo[n][W]= dp(W,wt,val,n-1); 
       }
    }
    
};



// } Driver Code Ends
class Solution
{
    //tabulation method
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code
        vector<vector<int> > t(n + 1, vector<int>(W + 1)); 
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i==0 || j==0)
               { //convert base case into initialzation 
                   t[i][j]=0;
               }
               else
               {
                   if(wt[i-1]<=j)
                   {
                       t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                   }
                   else
                   {
                       t[i][j]= t[i-1][j];
                   }
               }
           }
           
       }
       return t[n][W];
       
    }
};
