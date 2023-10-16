#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }

};

class linkList
{
    node* head;
    node* tail;

public:
    linkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int val)
    {
       node* newNode = new node(val);
       if(head == nullptr)
       {
         head = newNode;
         tail = newNode;
       }
       else{
         tail->next = newNode;
         tail = newNode;
       }
    }

    int middle()
    {
        int len = 0;
        node* temp = head;
        while(temp!= nullptr)
        {
            len++;
            temp = temp->next;
        }
         temp = head;
        for(int i=0;i<((len/2)-1);i++)
        {
          temp = temp->next;
        }

        return temp->data;
    }

    bool checkIsCircular()
    {
        // tail->next = head;
        node* temp = head;
        while(temp!=nullptr)
        {
            if(tail->next == head)
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
    //part 4
    int reverseLinkList()
    {
      node* curr = head;
      node* pre = nullptr;
      while(curr!= nullptr)
      {
         node* temp = curr;
         curr = curr->next;
          temp->next = pre;
          pre = temp;  
      }
      head = pre;
      return head->data;
    }

};

int main()
{
  linkList l;
  l.insert(4);
  l.insert(3);
  l.insert(3);
  l.insert(4);
//   cout<<l.middle();
//   cout<<l.checkIsCircular();
    cout<<l.reverseLinkList();
}