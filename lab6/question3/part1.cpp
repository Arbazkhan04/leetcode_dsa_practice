#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};
template <typename T>
class linkList
{
    Node<T>* head;
    Node<T>* tail;
public:
    linkList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insert(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
           tail->next = newNode;
           tail = newNode;
        }
    }
  
    void recursiveFun(Node<T>* temp)
    {
        if(temp==nullptr)
        {
            return;
        }
         cout<<temp->data<<"--->";
        temp = temp->next;
     
         recursiveFun(temp);
    }

    void displayRecursilvey()
    {
        recursiveFun(head);
    }

    void callReverseRecursively(Node<T>* curr, Node<T>* pre)
    {
        if(curr==nullptr)
        {
            head=pre;//update the head to pre beauxe it will not pront to nullptr;
            return;
        }
         Node<T>* temp = curr;
         curr = curr->next;
         temp->next = pre;
         pre = temp;
         callReverseRecursively(curr,pre);

    }

    T reverse()
    {
      callReverseRecursively(head,nullptr);
       return head->data;
    }

    void disply()
    {
        Node<T>* temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data;
            temp = temp->next;
        }
    }
};
int main()
{
   linkList<int> link;
   link.insert(5);
   link.insert(10);
      link.insert(10);
         link.insert(10);
            link.insert(20);
//    link.displayRecursilvey();
//    cout<<endl;
    cout<<link.reverse()<<endl;
    link.disply();
   return 0;
}