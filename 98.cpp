// validate binary search tree 
// TC=o(n) , SC=o(h)(h=height of the tree)
class Solution {
    public:
        bool validate(TreeNode *node , long minv , long maxv){
            if(!node) return true;
    
            if(node->val <= minv || node->val >= maxv) return false;
    
            return validate(node->left,minv , node->val) && validate(node->right,node->val,maxv);
        }
    
        bool isValidBST(TreeNode* root) {
            return validate(root,LONG_MIN,LONG_MAX);
        }
    };