// find kth smallest element in a bst 

// by using set (not prefered)

class Solution {
    public:
        // function for inserting in set 
        void insertset(set<int> &st ,TreeNode* root ){
            if(!root) return;
    
            st.insert(root->val);
            insertset(st,root->left);
            insertset(st,root->right);
        }
        int kthSmallest(TreeNode* root, int k) {
            set<int>st;
            insertset(st,root);
            auto it= st.begin();
            advance(it,k-1);
            
        return *it;
        }
    };


    class Solution {
        public:
            int k;
            
            int inOrder(TreeNode* node){
                if(!node) return -1;
                int lval = inOrder(node->left);
                if(lval != -1) return lval;
                if(--k == 0){
                    return node->val;
                }
                int rval = inOrder(node->right);
                if(rval != -1) return rval;
                return -1;
            };
            
            int kthSmallest(TreeNode* root, int k) {
                this->k = k;
                return inOrder(root);
            }
        };
        