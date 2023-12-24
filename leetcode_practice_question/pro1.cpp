
// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        int l=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            l++;
        }
        ListNode* t = head;
        for(int i=0;i<l/2;i++){
            s.push(t);
            t = t->next;
        }
        while(!s.empty()){
            ListNode* f = s.top();
            s.pop();
            if(t->val!=f->val){
                return false;
            }
            t = t->next;
        }
        return true;

    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* middle = mid(head);
       ListNode* rHead = rev(middle->next);
       while(rHead && head){
           if(head->val !=rHead->val){
               return false;
           }
           head = head->next;
           rHead=rHead->next;
       }
       return true;
    }
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* rev(ListNode* head){
        ListNode* pre = nullptr;
        while(head){
            ListNode* nextNode = head->next;
            head->next = pre;
            pre = head;
            head = nextNode;
        }
        return pre;
    }
};

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winner,losser;
        for(auto v:matches){
            int win = v[0];
            int loss = v[1];
            winner[win]++;
            losser[loss]++;
        }
        vector<int> w;
        for(auto [key,val]:winner){
            if(losser.find(key)==losser.end()){
                w.push_back(key);
            }
        }
        vector<int> l;
        for(auto [key,val]:losser)
        {
            if(val==1){
                l.push_back(key);
            }
        }
        sort(w.begin(),w.end());
        sort(l.begin(),l.end());
        vector<vector<int>> ans;
        ans.push_back(w);
        ans.push_back(l);
        return ans;
    }
};

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans=INT_MIN;
        for(auto num:nums){
            map[num]++;
        }
        for(auto [key,val]:map){
            if(val==1){
                ans = max(ans,key);
            }
        }
        return ans>0?ans:-1;
    }
};

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> map;
        for(char c:text){
            if(c=='a'||c=='b'||c=='l'||c=='o'||c=='n'){
                map[c]++;
            }
        }
        int ans = 0;
        for(auto [key,val]:map){
            if(key=='l'||key=='o'){
                val = val/2;
            }
            ans+=val;
        }
        return ans/5;
    }
};