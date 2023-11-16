#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};
class tree
{
public:
    Node *root;
    tree()
    {
        root = nullptr;
    }
    void insert(int data)
    {
        Node *node = new Node(data);
        if (!root)
        {
            root = node;
            return;
        }
        Node *temp = root;
        while (temp)
        {
            if (temp->data > node->data)
            {
                if (!temp->left)
                {
                    temp->left = node;
                    break;
                }
                temp = temp->left;
            }
            else if (temp->data < node->data)
            {
                if (!temp->right)
                {
                    temp->right = node;
                    break;
                }
                temp = temp->right;
            }
        }
    }
    bool searchInBst(Node *head, int data)
    {
        if (head == nullptr)
        {
            return false;
        }
        if (head->data == data)
        {
            return true;
        }
        bool left = searchInBst(head->left,data);
        bool right = searchInBst(head->right,data);
        return left||right;
    }
    void print(Node *head)
    {
        if (head == nullptr)
        {
            return;
        }
        cout << head->data << endl;
        print(head->left);
        print(head->right);
        return;
    }
    Node* start()
    {return root;}
};

int main()
{
    tree t;
    t.insert(5);
    t.insert(3);
    t.insert(1);
    t.insert(2);
    t.insert(9);
    t.print(t.root);
    cout<<t.searchInBst(t.root,1);
}