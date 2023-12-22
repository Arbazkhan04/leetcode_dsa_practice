
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