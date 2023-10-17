//question 1 with complete parts

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class linkList
{
    Node *head;
    Node *tail;

public:
    linkList()
    {
        head = nullptr; // inititally there is no node
        tail = nullptr; // inititally there is no node
    }
    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }

    void insertAtFront(int val)
    {
        Node *node = new Node(val);
        if (head == nullptr && tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            Node *temp = head;
            head = node;
            head->next = temp;
        }
    }

    void insetAtTail(int val)
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
            tail = newNode;
        }
    }

    void insetAtMid(int val)
    {

        Node *curr = new Node(val);
        Node *mid;

        int len = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        mid = head;
        if (len % 2 == 0)
        {
            for (int i = 1; i < len / 2; i++)
            {
                mid = mid->next;
            }
        }
        else
        {
            for (int i = 1; i <= len / 2; i++)
            {
                mid = mid->next;
            }
        }

        temp = mid->next;
        mid->next = curr;
        curr->next = temp;
    }

    // part 5
    void insetAfter(int val, int key)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        Node *next;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                next = temp->next;
                temp->next = newNode;
                newNode->next = next;
                break;
            }
            temp = temp->next;
        }
    }

    // part 5
    void insetBefore(int val, int key)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        Node *pre;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                pre->next = newNode;
                newNode->next = temp;
                break;
            }
            pre = temp;
            temp = temp->next;
        }
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return head->data;
        }
        return 0;
    }
    int getTail()
    {
        if (!isEmpty())
        {
            return tail->data;
        }
        return 0;
    }

    Node *search(int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void removeAtFront()
    {

        if (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        if (isEmpty())
        {
            head = nullptr;
            tail = nullptr;
        }
    }

    void removeTail()
    {
        Node* temp = head;

        while(temp->next != nullptr && temp->next->next != nullptr)
        {
           temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        tail = temp;

        if(isEmpty())
        {
            head = nullptr;
            tail = nullptr;
        }
    }

    void removeMiddle()
    {
         int len = 0;
         Node* temp = head;
         Node* next;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        temp = head;
        len =(len/2)-1;
        for(int i = 0;i<len;i++)
        {
          if(i+1 == len)
          {
            break;
          }
          temp = temp->next;
        }
         temp->next = temp->next->next;
    }

    void display()
    {

        while (head != nullptr)
        {
            cout << head->data << "---->";
            head = head->next;
        }
    }
};

int main()
{
    linkList l1;
    l1.insertAtFront(5);
    l1.insertAtFront(6);
    l1.insertAtFront(8);
    l1.insetAtTail(9);
    // l1.insetAtMid(7);
    // l1.insetAfter(4, 5);
    // l1.insetBefore(22, 6);
    // cout << l1.getFront();
    // cout << l1.getTail();
    // cout << l1.search(8)->data;
    // l1.removeAtFront();
    // l1.removeTail();
    l1.removeMiddle();
    l1.display();

    // cout<<l1.search(8);
}




//question 2 part 1 

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
public:
    Node<T> *head;
    Node<T> *tail;
    linkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFront(T val)
    {
        Node<T> *node = new Node(val);
        if (head == nullptr && tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            Node<T> *temp = head;
            head = node;
            head->next = temp;
        }
    }

    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }

    T getTail()
    {
        Node<T> *temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        T val = temp->next->data;
        temp->next = nullptr;
        tail = temp;
        delete temp;
        return val;
    }
};

template <typename T>
class stack
{

    linkList<T> S;

public:
    stack() {}

    void push(T val)
    {
        S.insertAtFront(val);
    }

    T pop()
    {
       return  S.getTail();
    }

    bool isEmpty()
    {
        return S.isEmpty();
    }
};

int main()
{
    stack<int> S;
    S.push(5);
    S.push(6);
    cout<<S.pop();
    cout<<S.isEmpty();
}

// question 2 part 2

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


// question 3 part 1

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


// question 3 part 2 

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