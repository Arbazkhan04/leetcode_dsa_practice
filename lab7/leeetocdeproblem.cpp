

problem  1 
https://leetcode.com/problems/merge-two-sorted-lists/submissions/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ptr1 = list1;
    ListNode* ptr2 = list2;
    ListNode* newList;
    if(list1==nullptr)
    {
        return list2;
    }
    if(list2==nullptr)  
    {
        return list1;
    }
    vector<ListNode*> list;
    while(ptr1!=nullptr && ptr2!=nullptr)
    {
        if(ptr1->val < ptr2->val)
        {
            list.push_back(ptr1);
            ptr1=ptr1->next;
        }
        else
        {
            list.push_back(ptr2);
             ptr2 = ptr2->next;
        }
    }
    ptr1==nullptr?list.push_back(ptr2):list.push_back(ptr1);
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(ListNode* node : list)
    {
        if(head==nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
      return head;  
        
    }
};


https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
problem 2

class Solution {
public:
    ListNode* newHead = nullptr;
    ListNode* newTail = nullptr;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == nullptr)
        {
            return nullptr;
        }
        
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
         
            temp = temp->next;
            len++;
        }
       int removeLen = len - n;
        temp = head;
       for(int i = 0;i<removeLen;i++)
       {
           insert(temp);
           temp = temp->next;
       }
       if(temp->next == nullptr)
       {
           insert(nullptr);
       }
        else
        {
            insert(temp->next);
        }
       return newHead;
    } 
    void insert(ListNode* node)
    {
        if(newHead == nullptr)
        {
            newHead = node;
            newTail = node;
        }
        else 
        {
            newTail->next =node;
            newTail = node;
        }
    }
};

problem 3 


https://leetcode.com/problems/swap-nodes-in-pairs/submissions/

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
   
    
    ListNode* swapPairs(ListNode* head) {
      ListNode* dummy = new ListNode(0);
      ListNode* curr = dummy;
      while(head!=nullptr && head->next!=nullptr)
      {
         ListNode* n1 = head;
         ListNode* n2 = head->next;
         
          curr->next = n2;
           n1->next = n2->next;
          n2->next = n1;
          curr = n1;
          
          head = n1->next;
      }
        
        return dummy->next;
    }
};


//problem 4 

https://leetcode.com/problems/reverse-linked-list-ii/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     ListNode* dummy = new ListNode(0);
     ListNode* curr = dummy;
     ListNode* pre=nullptr;
     int count = 1;
     while(count!=left)
     {
        curr->next = head;
         curr = head;
         head = head->next;
         count++;
     }
     stack<ListNode*> reverse;
     while(left<=right)
     {
         reverse.push(head);
         head = head->next;
         left++;
     }
     
    while(!reverse.empty())
    {
        ListNode* temp = reverse.top();
        curr->next = temp;
        curr = temp;
        reverse.pop();
    }   
    curr->next = head;
        return dummy->next;
    }
};