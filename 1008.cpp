// Build a BST from its preorder traversal 
// tc = o(n),sc = o(logn)(recursion) 


class Solution {
    public:
        TreeNode* build(vector<int>& arr,int& i,int bound){
            if(i == arr.size() || arr[i]>bound) return NULL;
    
            TreeNode* node = new TreeNode(arr[i++]);
    
            node->left = build(arr,i,node->val);
            node->right = build(arr,i,bound);
            return node;
        }
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int i=0;
            return build(preorder,i,INT_MAX);
        }
    };