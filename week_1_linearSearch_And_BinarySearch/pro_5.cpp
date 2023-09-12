
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxSum=-99999;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum>maxSum)
            {
                maxSum=sum;
            }
        }
        
        return maxSum;
        
    }
};
