class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>> t(arr.size()+1,vector<bool>(sum+1));
        for(int i=0;i<=arr.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0){
                    t[0][j]=false;
                }
                if(j==0){
                    t[i][0]=true;
                }
                
            }
        }
        for(int i=1;i<=arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[arr.size()][sum];
    }
};