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