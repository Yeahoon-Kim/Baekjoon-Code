#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool isIn(pair<int, int> p, int m, int n) {
    return (p.first >= 0 && p.first < m && p.second >= 0 && p.second < n);
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(m, vector<int>(n));
    queue<pair<int, int>> q;
    set<pair<int, int>> ps;
    const int MOD = 1e9+7;
    
    for(auto& a : puddles) ps.insert({a[0]-1, a[1]-1});
    
    dp[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        pair<int, int> right = {current.first+1, current.second};
        pair<int, int> down = {current.first, current.second+1};
        
        if(isIn(right, m, n) && ps.count(right) == 0) {
            if(dp[right.first][right.second] == 0) q.push(right);
            dp[right.first][right.second] += dp[current.first][current.second];
            dp[right.first][right.second] %= MOD;
        }
        if(isIn(down, m, n) && ps.count(down) == 0) {
            if(dp[down.first][down.second] == 0) q.push(down);
            dp[down.first][down.second] += dp[current.first][current.second];
            dp[down.first][down.second] %= MOD;
        }
    }
    
    return dp[m-1][n-1];
}