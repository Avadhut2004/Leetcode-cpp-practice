//  find no of nodes in a complete binary tree 

// Brute approach 

class Solution {
    public:
        int count(TreeNode* root){
            if(!root) return 0;
    
            return 1+ count(root->left)+count(root->right);
        }
        int countNodes(TreeNode* root) {
            return count(root);
        }
};
// TC = O(N)

// Optimal solution 

class Solution {
    public:
        int findheightl(TreeNode* root){
            int cnt=0;
            while(root){
                cnt++;
                root = root->left;
            }
    
            return cnt;
        }
    
        int findheightr(TreeNode* root){
            int cnt=0;
            while(root){
                cnt++;
                root = root->right;
            }
    
            return cnt;
        }
        int countNodes(TreeNode* root) {
            if(!root) return 0;
    
            int lh = findheightl(root);
            int rh = findheightr(root);
    
            if(lh==rh){
                return (1<<lh)-1;
            }
    
            return 1+countNodes(root->left) + countNodes(root->right);
        }
    };

    // TC = O(logN * logN);