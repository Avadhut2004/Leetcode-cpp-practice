//  find all possible recipies 

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<string>> graph;
            unordered_map<string, int> inDegree;
            unordered_set<string> available(supplies.begin(), supplies.end());
    
            for (int i = 0; i < recipes.size(); i++) {
                for (const string& ingredient : ingredients[i]) {
                    graph[ingredient].push_back(recipes[i]);
                    inDegree[recipes[i]]++;  // Count required ingredients for each recipe
                }
            }
    
            queue<string> q;
            for (const string& supply : supplies) {
                q.push(supply);  // Start with available supplies
            }
    
            vector<string> result;
            while (!q.empty()) {
                string item = q.front();
                q.pop();
                
                if (find(recipes.begin(), recipes.end(), item) != recipes.end()) {
                    result.push_back(item);  // If it's a recipe, add to result
                }
    
                for (const string& recipe : graph[item]) {
                    if (--inDegree[recipe] == 0) {  // If all ingredients are available
                        q.push(recipe);
                    }
                }
            }
    
            return result;
        }
    };
    