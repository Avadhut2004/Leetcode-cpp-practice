// Search in a BST 
// TC + O(logn)
class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            if(!root || root->val==val) return root;
            
            if(root->valval) return searchBST(root->right,val);
            
            return searchBST(root->left,val);
        }
    };