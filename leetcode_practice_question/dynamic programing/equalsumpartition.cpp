class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;
       for(auto num:nums){
           sum+=num;
       } 
       if(sum%2!=0){
           return false;
       }
       return subsetSum(nums,sum/2);
    }
    bool subsetSum(vector<int> nums,int sum){
         int s = nums.size();
         vector<vector<bool>> t(s+1,vector<bool>(sum+1));
         for(int i=0;i<=s;i++){
             for(int j=0;j<=sum;j++){
                 if(i==0){
                     t[i][j]=false;
                 }
                 if(j==0){
                     t[i][j]=true;
                 }
             }
         }
         for(int i=1;i<=s;i++){
             for(int j=1;j<=sum;j++)
             {
                 if(nums[i-1]<=j){
                     t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                 }
                 else{
                     t[i][j]=t[i-1][j];
                 }
             }
         }
         return t[s][sum];
    }
};