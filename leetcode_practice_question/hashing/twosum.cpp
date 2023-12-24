
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

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        int ans =0;
        for(char c:magazine){
            map[c]++;
        }
        for(char c:ransomNote){
            if(map.find(c)!=map.end()){
                map[c]--;
                if(map[c]==0){
                    map.erase(c);
                }
                ans++;
            }
        }
        return ans==ransomNote.size();
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> jewel;
        for(char c:jewels){
            jewel[c]++;
        }
        int ans=0;
        for(auto c:stones){
            if(jewel.find(c)!=jewel.end()){
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int left = 0;
       int ans=0;
       unordered_map<char,int> seen;
       for(int i=0;i<s.size();i++)
       {
           if(seen.find(s[i])!=seen.end()){
               while(seen[s[i]]>0){
                    seen[s[left]]--;
                    left++;
               }
               seen.erase(s[i]);
           }
          seen[s[i]]++;
          ans = max(ans,i-left+1);
       }
       return ans; 
    }
};