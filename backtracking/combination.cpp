class Solution {
public:
    int k;
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        vector<int> curr = {};
        vector<vector<int>> ans;
        backtrack(curr,ans,1,n);
        return ans;
    }
    void backtrack(vector<int> curr,vector<vector<int>>& ans,int j,int n){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }   
    
        for(int i=j;i<=n;i++){
            curr.push_back(i);
            backtrack(curr,ans,i+1,n);
            curr.pop_back();
        }
        return;
    }
};