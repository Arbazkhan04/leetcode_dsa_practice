// recursive soltion
class Solution {
public:
    vector<int> cost;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        return dp(cost.size());
    }
    int dp(int i){
        if(i==0 || i==1){
            return 0;
        }
        return min(cost[i-1]+dp(i-1),cost[i-2]+dp(i-2));
    }
};

//buttom up solution
class Solution {
public:
    vector<int> cost;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        return dp(cost.size());
    }
    int dp(int n){
        vector<int> dp(n+1);
        dp[1]=0;//convert base case;
        for(int i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};