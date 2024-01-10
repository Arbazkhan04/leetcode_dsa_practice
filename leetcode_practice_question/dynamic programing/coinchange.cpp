class Solution {
public:
    int amount;
    vector<int> coins;
    int coinChange(vector<int>& coins, int amount) {
      this->amount = amount;
      this->coins = coins;
     int result =  dfs(coins.size());
     return result>0?result:-1;
    }
    int dfs(int n){
        if(n==0){
            return 0;
        }
        if(coins[n-1]<=amount){
            amount = amount - coins[n-1];
            return 1+dfs(n);
        }
        else{
            return dfs(n-1);
        }
    }
};