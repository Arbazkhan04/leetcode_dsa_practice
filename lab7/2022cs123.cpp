#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *pre;
  Node(int val)
  {
    data = val;
    next = nullptr;
    pre = nullptr;
  }
};

class linkList
{
public:
  Node *head;
  Node *tail;

  linkList()
  {
    head = nullptr;
    tail = nullptr;
  }

  class forwotd_iterator
  {
    Node *iter;

  public:
    forwotd_iterator(Node *p)
    {
      iter = p;
    }

    forwotd_iterator operator++()
    {
      iter = iter->next;
      return iter;
    }

    bool operator!=(const forwotd_iterator &n)
    {
      return iter != n.iter;
    }

    bool operator==(const forwotd_iterator &other)
    {
      return iter == other.iter;
    }
    int operator*()
    {
      return iter->data;
    }
  };

  class reverse_iterator
  {
    Node *iter;

  public:
    reverse_iterator(Node *p)
    {
      iter = p;
    }

    Node *operator++()
    {
      return iter = iter->pre;
    }

    bool operator==(const reverse_iterator &other)
    {
      return iter == other.iter;
    }

    bool operator!=(const reverse_iterator &other)
    {
      return iter != other.iter;
    }

    int operator*()
    {
      return iter->data;
    }
  };

  class generalIterator
  {
    Node *iter;

  public:
    generalIterator(Node *p)
    {
      iter = p;
    }

    Node *operator++()
    {
      return iter = iter->next;
    }

    Node *operator--()
    {
      return iter = iter->pre;
    }

    bool operator==(const generalIterator &other)
    {
      return iter == other.iter;
    }

    bool operator!=(const generalIterator &other)
    {
      return iter != other.iter;
    }

    int operator*()
    {
      return iter->data;
    }
  };

  generalIterator begin()
  {
    return generalIterator(head);
  }
  generalIterator end()
  {
    return generalIterator(nullptr);
  }

  forwotd_iterator fbegin()
  {
    return forwotd_iterator(head);
  }

  forwotd_iterator fend()
  {
    return forwotd_iterator(nullptr);
  }

  reverse_iterator rBegin()
  {
    return reverse_iterator(tail);
  }

  reverse_iterator rend()
  {
    return reverse_iterator(nullptr);
  }

  void insetNode(int val)
  {
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->pre = tail;
      tail = newNode;
    }
  }
  bool isempty()
  {
    return head == nullptr;
  }

  void insertAtFront(int val)
  {
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->pre = newNode;
      head = newNode;
    }
  }

  void insertAtTail(int val)
  {
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->pre = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  void removeAt(int pos)
  {
    if (head == nullptr)
    {
      cout << "linklist is empty" << endl;
      return;
    }
    else if (pos == 0)
    {
      head = head->next;
      head->pre = nullptr;
      return ;
    }
    else
    {
      int len = 0;
      Node* temp = head;
      while(temp!=nullptr && len<pos)
      {
        temp = temp->next;
        len++;
      }

      Node* pre = temp->pre;
      Node* next = temp->next;
      if(next == nullptr)
      {
        pre->next = nullptr;
      }
      else 
      {
        pre->next = next;
        next->pre = pre;
      }
    }
  }
};
int main()
{
  linkList link;
  link.insetNode(5);
  link.insetNode(6);
  link.insetNode(6);
  link.insertAtFront(9);
  link.insertAtTail(4);
  link.insertAtTail(4);
  link.removeAt(0);
  cout << "forward iterator";
  for (linkList::forwotd_iterator i = link.fbegin(); i != link.fend(); ++i)
  {
    cout << *i;
  }
  cout << endl;

  // cout<<"Revesed iteator";

  // for(linkList::reverse_iterator r = link.rBegin();r!=link.rend();++r)
  // {
  //   cout<<*r;
  // }
  // cout<<endl;

  // cout<<"general iterator with increament";
  // for(linkList::generalIterator g= link.begin();g!=link.end();++g)
  // {
  //   cout<<*g;
  // }
  // cout<<endl;

  // cout<<"general iterator with decrement";
  // for(linkList::generalIterator g= link.begin();g!=link.end();--g) //there is bug we have to move begin to tail and --operator load to tail then it will work perfectly
  // {
  //   cout<<*g;
  // }
  cout << endl;
}







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



class node
{
public:
    int data;
    node* next;
    node* pre;
    node(int val)
    {
        data = val;
        next = nullptr;
        pre = nullptr;
    }
    
};

https://leetcode.com/problems/design-linked-list/submissions/
// problem 5;

class MyLinkedList {
private:
    node* head;
    node* tail;
public:
    MyLinkedList() {
        head=nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        int ind=0;
        node* temp=head;
        while(temp!=nullptr)
        {
          if(ind==index)
          {
              return temp->data;
          }
            ind++;
            temp= temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        node* newNode  = new node(val);
        if(head==nullptr)
        {
            head=newNode;
            tail = newNode;
        }
        else
        {
            head->pre = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        node* newNode = new node(val);
        if(head==nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        node* newNode = new node(val);
        if(index==0)
        {
           addAtHead(val); 
        }
        else
        {
        int ind = 0;
        node* temp = head;
        while(temp!=nullptr)
        {
            if(temp->next == nullptr && ind == index-1)
            {
                addAtTail(val);
                break;
            }
            if(ind == index)
            {
                newNode->next = temp;
                newNode->pre = temp->pre;
                if (temp->pre != nullptr) {
                    temp->pre->next = newNode;
                } else {
                    head = newNode; 
                }
                temp->pre = newNode;
                break;
            }
            temp = temp->next;
            ind++;
        }
        }
    }
    
    void deleteAtIndex(int index) {
        if(index == 0)
        {
            head = head->next;
            head->pre = nullptr;
        }
         int ind = 0;
        node* temp = head;
        while(temp!=nullptr)
        {
            if(temp->next == nullptr)
            {
                temp->pre->next = nullptr;
                break;
            }
            
            if(ind == index)
            {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                break;
            }
            ind++;
            temp = temp->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

