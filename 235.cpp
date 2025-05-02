// LCA of a BST

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        if(pval>qval) swap(pval,qval);
        
         while(root){
            if(qval<root->val) root = root->left;
            else if(pval>root->val) root = root->right;
            else return root;
         }   
         return NULL;
        }
    };