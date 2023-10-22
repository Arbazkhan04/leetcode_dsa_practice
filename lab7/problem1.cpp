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