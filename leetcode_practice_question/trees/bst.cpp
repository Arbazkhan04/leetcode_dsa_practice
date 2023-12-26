#include <iostream>
using namespace std;

template <typename T>
class BST {
public:
    class Node {
    public:
        T data;
        Node* leftchild;
        Node* rightchild;

        Node(T val)
        {
            data = val;
            leftchild = nullptr;
            rightchild = nullptr;
        }
    };

    Node* tree;
    
    void insert(T value)
    {
        insert(tree, value);
    }
    void insert(Node*& tree, T value)
    {
        if (tree == nullptr)
        {
            tree = new Node(value);
            return;
        }
        if (value < tree->data)
        {
             insert(tree->leftchild, value);
        }
        else
        {
             insert(tree->rightchild, value);
        }
    }
    void search(T value)
    {
       Node* result =  search(tree, value);
       if (result)
       {
           cout << "key ", result, "is found";
       }
       else
       {
           cout << "key ", result, "is not found";
       }
    }

    Node* search(Node* tree, T value)
    {
        if (tree == nullptr || tree->data == value)
        {
            return tree;
        }
        else if (value < tree->data)
        {
            return search(tree->leftchild, value);
        }
        else
        {
            return search(tree->rightchild, value);
        }
    }
    void print(Node* tree)
    {
         if(tree == nullptr)
         {
             return;
         }
            print(tree->leftchild); 
            cout << tree->data << " ";
            print(tree->rightchild);
            return ;
    }
};

int main()
{
    BST<int> tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.search(30);
    tree.print(tree.tree);
}