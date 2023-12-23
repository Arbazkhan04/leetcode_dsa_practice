
https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(map.find(nums[i])!=map.end()){
                return {map[nums[i]],i};
            }
            map[comp]=i;
        }
        return {-1,-1};
    }
};

https://leetcode.com/problems/first-letter-to-appear-twice/
class Solution {
public:
    char repeatedCharacter(string s) {
       unordered_map<char,int> map;
       for(auto c:s){
           if(map.find(c)!=map.end()){
               return c;
           }
           map[c]++;
       }
       return ' ';
    }
};