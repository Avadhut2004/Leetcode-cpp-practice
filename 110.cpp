// balanced binary tree 

class Solution {
    public:
        int checkheight(TreeNode* root){
            if(!root ) return 0;
            int lh = checkheight(root->left);
            if(lh == -1) return -1;
    
            int rh = checkheight(root->right);
            if(rh == -1) return -1;
    
            if(abs(lh-rh) > 1) return -1;
    
            return 1+max(lh , rh);
        }
        bool isBalanced(TreeNode* root) {
            return (checkheight(root)!= -1);
        }
    };