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
    int count;
    tree()
    {
        root = nullptr;
        count = 0;
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
        bool left = searchInBst(head->left, data);
        bool right = searchInBst(head->right, data);
        return left || right;
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
    Node *start()
    {
        return root;
    }

    void Even_Counts(Node *head)
    {
        if (!head)
        {
            return;
        }
        if (head->data % 2 == 0)
        {
            count++;
        }
        Even_Counts(head->left);
        Even_Counts(head->right);

        return;
    }
    int heightOfBST(Node *head)
    {
        int ans = helper(head, 0);
        return ans - 1;
    }
    int helper(Node *temp, int count)
    {
        if (!temp)
        {
            return 0;
        }
        int left = helper(temp->left, count);
        int right = helper(temp->right, count);
        return 1+max(left,right);
    }
    void sort(){
        
    }
};

int main()
{
    tree t;
    t.insert(6);
    t.insert(5);
    t.insert(3);
    t.insert(4);
    cout << t.heightOfBST(t.root) << endl;
    t.Even_Counts(t.root);
    cout << t.count << "Even number ";
    t.print(t.root);
    cout << t.searchInBst(t.root, 1);
}


//https://leetcode.com/problems/validate-binary-search-tree/

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(root->left){
          if(root->val<root->left->val){
                return false;
            }
            if(root->val==root->left->val){
                return false;
            }
        }
        if(root->right)
        {
            if(root->val>root->right->val){
                return false;
            }
             if(root->val==root->right->val){
                return false;
            }
        }
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
            
        
        return left && right;
    }
};*/