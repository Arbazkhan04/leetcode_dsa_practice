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

template<typename T> 
class linkList
{
  Node<T>* head;
  Node<T>* tail;  
public:
   linkList() 
   {
     head=nullptr;
     tail = nullptr;
   }

   void isertAtTail(T val)
   {
      Node<T>* newNode = new Node(val);
      Node<T>* temp = head;
      if(head==nullptr)
      {
        head = newNode;
        tail = newNode;
      }
      else 
      {
         head = newNode;
         head->next = temp;
      }
   }

   bool isEmpty()
   {
    return head==nullptr;
   }

   T removeAtTail()
   {
     Node<T>* temp = head;
     while(temp->next!=nullptr && temp->next->next!=nullptr)
     {
       temp = temp->next;
     }
     T val = temp->next->data;
     delete temp->next;
     temp->next = nullptr;
     tail = temp;
     return val;

   }
};
template<typename T>
class Queue
{
  linkList<T> Q;
public:
  Queue(){}

  void Enqueue(T val)
  {
    Q.isertAtTail(val);
  }
 
  T Dequeue()
  {
    return Q.removeAtTail();
  }

  bool isEmpty()
  {
    return Q.isEmpty();
  }
};
int main()
{
  Queue<int> Q;
 cout<<Q.isEmpty();
  Q.Enqueue(5);
  Q.Enqueue(6);
  Q.Enqueue(4);
  Q.Enqueue(3);
  Q.Enqueue(2);
  cout<<Q.Dequeue();
    cout<<Q.Dequeue();
      cout<<Q.Dequeue();
}