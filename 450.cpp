// deleting a node in a bst 


class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
                if(!root) return NULL;
                if(key <root->val ){
                    root->left = deleteNode(root->left , key);
                }
                else if (key > root->val){
                    root->right = deleteNode(root->right , key);
                }
    
                else{
                    // node found 
    
                    if(!root->left) return root->right;
    
                    if(!root->right) return root->left;
    
                    // when two children , find the inorder successor and replace root with it 
    
                    TreeNode* temp = root->right;
                    while(temp->left){
                        temp = temp->left;
                    }
    
                    root->val = temp->val;
                    root->right = deleteNode(root->right , temp->val);
                }
    
                return root ;
        }
    };