class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            vector<bool> visited(n, false);
    
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
    
            int completeCount = 0;
    
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    queue<int> q;
                    q.push(i);
                    visited[i] = true;
    
                    unordered_set<int> componentNodes;
                    int edgeCount = 0;
    
                    while (!q.empty()) {
                        int node = q.front();
                        q.pop();
                        componentNodes.insert(node);
    
                        for (int neighbor : adj[node]) {
                            edgeCount++; 
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push(neighbor);
                            }
                        }
                    }
    
                    int nodes = componentNodes.size();
                    if (edgeCount / 2 == (nodes * (nodes - 1)) / 2) {
                        completeCount++;
                    }
                }
            }
    
            return completeCount;
        }
    };
    