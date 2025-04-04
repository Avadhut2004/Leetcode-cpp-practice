// Lca of deepest leeves 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        pair<int,TreeNode*> dfs(TreeNode* root){
            if(!root) return{0,root};
    
            auto left = dfs(root->left);
            auto right = dfs(root->right);
    
            int leftdepth = left.first;
            int rightdepth = right.first;
    
            if(leftdepth == rightdepth) return {leftdepth+1,root};
            return (leftdepth>rightdepth)? make_pair(leftdepth+1,left.second):make_pair(rightdepth+1,right.second);
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfs(root).second;
        }
    };