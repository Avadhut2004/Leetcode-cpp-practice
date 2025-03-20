// zigzag level order traversal \

class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            queue<TreeNode*> q;
            if(root==NULL) return ans;
            q.push(root);
            int flag = 1;  // 1== ltor -1 == rtol
    
               
                while(!q.empty()){
                vector<int>level;
                int len = q.size();
                for (int i = 0; i < len; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
    
                if (!flag) {
                    reverse(level.begin(), level.end());
                }
    
                ans.push_back(level);
                flag = !flag; 
            }
          return ans;
        }
    };