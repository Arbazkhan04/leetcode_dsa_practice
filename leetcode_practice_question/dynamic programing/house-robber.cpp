// recusrive solution
class Solution {
public:
    vector<int> nums;
    int rob(vector<int>& nums) {
      this->nums = nums;
      return dp(nums.size());
    }
    int dp(int n){
        if(n<=0){
            return 0;
        }
        return max(nums[n-1]+dp(n-2),dp(n-1));
    }
};

// buttom up solution
class Solution {
public:
    vector<int> nums;
    int rob(vector<int>& nums) {
        if(nums.size()<=0){
            return 0;
        }
      this->nums = nums;
      return dp(nums.size());
    }
    int dp(int n){
        vector<int> dp(n+2);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};