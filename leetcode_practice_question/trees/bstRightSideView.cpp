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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
     if(!root){return {};}
      vector<int> ans;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
          int size = q.size();
          ans.push_back(q.back()->val);
          for(int i=size;i>0;i--){
              TreeNode* node = q.front();
              q.pop();
              if(node->left){
                  q.push(node->left);
              }
              if(node->right){
                  q.push(node->right);
              }
            }
          }
           return ans;
         
      }
};