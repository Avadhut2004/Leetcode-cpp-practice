// diameter of the binary tree 

class Solution {
    public:
    int diameter = 0;
        int checkheight(TreeNode* root){
            if(!root )return 0;
    
            int lh = checkheight(root->left);
            int rh = checkheight(root->right);
    
            diameter = max(diameter , lh+rh);
    
            return 1+max(lh,rh);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int height = checkheight(root);
    
            return diameter;
        }
    };