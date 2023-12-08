#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    int height;
    node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
    }    
};

class avlTree{
    node* root;
    avlTree(){
        this->root = nullptr;
    }
    void insert(int data){
        if(!root){
            root = new node(data);
        }
        else{
            isnertHelper(root, data);
        }
    }
    void isnertHelper(node* root,int data){
        if(root->data > data){
            if(root->left){
                isnertHelper(root->left,data);
            }
            else{
                root->left = new node(data);
            }
        }
        else{
            if(root->right){
                isnertHelper(root->right,data);
            }
            else{
                root->right = new node(data);
            }
        }
    }
    int heightDifference(node* n){
        return abs(height(n->left)-height(n->right));
    }
    int height(node* node){
        if(!node){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        return 1+max(left,right);
    }
    bool isBalanced(node* n){
        int height = heightDifference(n);
        return height<=1 ? true : false;
    }
};

int main(){

}