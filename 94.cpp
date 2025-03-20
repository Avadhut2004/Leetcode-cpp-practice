// inorder traversal of binary trees 
class Solution {
    public:
        void in(vector<int>&ans,TreeNode *root){
                if(root == NULL)return;
        
                in(ans,root->left);
                ans.push_back(root->val);
                in(ans,root->right);
            }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            in(ans,root);
    
            return ans;
        }
    };