https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_set<string> set;
      unordered_set<string> newSet;
      for(int i=0;i<s.size();i++){
          string st = s.substr(i,10);
          if(set.find(st)==set.end())
          {
              set.insert(st);
          }
          else{
              newSet.insert(st);
          }
      }
        vector<string> ans;
        for(auto st:newSet){
            ans.push_back(st);
        }
      return ans;
    }
};

https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto st:strs)
        {
            string unoStr = st;
            sort(st.begin(),st.end());
            map[st].push_back(unoStr);
        }
        vector<vector<string>> ans;
        for(auto [key,val]:map){
            ans.push_back(val);
        }
        return ans;
    }
};