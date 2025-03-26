// All nodes at a distance K in a binary tree 




class Solution {
    public:
        unordered_map<int, vector<int>> adj;  // Adjacency list for the tree graph
        
        void buildGraph(TreeNode* root, TreeNode* parent) {
            if (!root) return;
            
            if (parent) {
                adj[root->val].push_back(parent->val);
                adj[parent->val].push_back(root->val);
            }
            
            buildGraph(root->left, root);
            buildGraph(root->right, root);
        }
        
        vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
            buildGraph(root, nullptr);  // Convert tree into graph
            
            queue<int> q;
            unordered_set<int> visited;
            vector<int> result;
            
            q.push(target->val);
            visited.insert(target->val);
            
            while (!q.empty() && K--) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int node = q.front();
                    q.pop();
                    
                    for (int neighbor : adj[node]) {
                        if (visited.count(neighbor) == 0) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            
            while (!q.empty()) {
                result.push_back(q.front());
                q.pop();
            }
            
            return result;
        }
    };
    