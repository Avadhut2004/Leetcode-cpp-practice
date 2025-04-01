// solving questions with brainpower

class Solution {
    public:
        vector<long long> memo;
        
        long long solve(int i, vector<vector<int>>& questions) {
            if (i >= questions.size()) return 0;
            if (memo[i] != -1) return memo[i];
    
            int next = i + questions[i][1] + 1;
            long long take = questions[i][0] + solve(next, questions);
            long long skip = solve(i + 1, questions);
    
            return memo[i] = max(take, skip);
        }
    
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            memo.assign(n, -1);
            return solve(0, questions);
        }
    };
    