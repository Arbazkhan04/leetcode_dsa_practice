class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits ==""){return {};}
        unordered_map<char,string> map ={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}
        };
        string curr = "";
        vector<string> ans;
        backtrack(map,curr,ans,digits,0);
        return ans;
    }

    void backtrack(unordered_map<char,string> map, string curr,vector<string>& ans,string digit,int index)
    {
        if(curr.size()==digit.size()){
            ans.push_back(curr);
            return;
        }
        char dg = digit[index];
        string str = map[dg];
        for(char c:str){
             if(curr.find(to_string(c))==string::npos){
                 curr.push_back(c);
                 backtrack(map,curr,ans,digit,index+1);
                 curr.pop_back();
             }
        }
    }

};