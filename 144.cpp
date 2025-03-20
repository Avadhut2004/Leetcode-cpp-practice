// preorder traversal of a binary tree 

class Solution {
    public:
        void pre(vector<int>&ans,TreeNode *root){
            if(root == NULL)return;
    
            ans.push_back(root->val);
            pre(ans,root->left);
            pre(ans,root->right);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            pre(ans,root);
    
            return ans;
        }
    };