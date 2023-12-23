class Solution {
public:
    bool checkIfPangram(string sentence) {
    unordered_set<char> set;
    for(auto c:sentence){
        set.insert(c);
    }
    return set.size()==26;
    }
};

class Solution {
public:
    int countElements(vector<int>& arr) {
      int count=0;
      unordered_set<int> set;
      for(auto num:arr){
          set.insert(num);
      }
      for(int num:arr){
          if(set.find(num+1)!=set.end()){
              count++;
          }
      }
      return count;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unordered_set<int> set(nums.begin(),nums.end());
       for(int i=0;i<=nums.size();i++){
           if(set.find(i)==set.end()){
               return i;
           }
       }
       return -1;
    }
};