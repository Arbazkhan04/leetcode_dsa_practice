class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr = {};
        vector<vector<int>> ans;
        backtrack(curr,ans,nums,0);
        return ans;
    }
    void backtrack(vector<int>& curr,vector<vector<int>>& ans, vector<int> nums,int j){
        if(j>nums.size()){
            return;
        }
        ans.push_back(curr);
        for(int i=j;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(curr,ans,nums,i+1);
            curr.pop_back();
        }
        return;
    }
};