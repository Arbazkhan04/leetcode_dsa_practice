First Question 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int count = 0;
    vector<int> ans;
        for(int outer =0;outer<nums.size();outer++)
        {
            for(int inner=0;inner<nums.size(); inner++)
            {
                if(outer==inner)
                {
                    continue;
                }
                else if(nums[outer]!=nums[inner] && nums[outer]>nums[inner])
                {
                    count++;
                }
            }
            
            ans.push_back(count);
            count=0;
        }
        
        return ans;
    }
};
