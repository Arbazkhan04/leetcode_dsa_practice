#include <iostream>
#include<vector>
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
       vector<int> num = {5,3,9,1,2,6,7};
       for(int n : num){
           insert(n);
       }
       // helper funciton to soet the array;
       cout<<"sorted data "<<endl;

        helper(root);
    }

     void helper(Node* head){
       if(head==nullptr){
        return;
       }
       helper(head->left);
       cout<<head->data<<" ";
       helper(head->right);
    }

    int internalNodeCount(Node* head){
        if(head==nullptr){
            return 0;
        }
        int count = 0;
        if((head->left && !(head->right)) ||  (!(head->right)&& head->left)){
          count++;
        }
        count+=internalNodeCount(head->left)+internalNodeCount(head->right);
       return count;
    }
    int countLeave(Node* head){
        if(head==nullptr){
            return 0;
        }
        int num =0;
        if(!head->left && !head->right){
        num++;
        }
        num+=countLeave(head->left)+countLeave(head->right);

        return num;
    }
};

int main()
{
    tree t;
    t.sort();
    cout<<endl;
    cout<<t.internalNodeCount(t.root);
    cout<<t.countLeave(t.root);

    // t.insert(6);
    // t.insert(5);
    // t.insert(3);
    // t.insert(4);
    // cout << t.heightOfBST(t.root) << endl;
    // t.Even_Counts(t.root);
    // cout << t.count << "Even number ";
    // t.print(t.root);
    // cout << t.searchInBst(t.root, 1);
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


// question no 5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
        
//         vector<vector<int>> result;
//         if(root==nullptr){
//             return result;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             vector<int> curr;
//             int size = q.size(); // find the current size of queue;
//             for(int i=0;i<size;i++){
//                 TreeNode* top = q.front();
//                 q.pop();
//                 if(top->left){
//                     q.push(top->left);
//                 }
//                 if(top->right){
//                     q.push(top->right);
//                 }
//                 curr.push_back(top->val);   
//             }
//             result.push_back(curr);
//         }
//         return result;
//     }
// };