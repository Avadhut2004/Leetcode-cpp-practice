// post order traversal of a binary tree 

class Solution {
    public:
         void post(vector<int>&ans,TreeNode *root){
                    if(root == NULL)return;
            
                    post(ans,root->left);
                    post(ans,root->right);
                    ans.push_back(root->val);
                }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int>ans;
            post(ans,root);
            return ans;
        }
    };