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