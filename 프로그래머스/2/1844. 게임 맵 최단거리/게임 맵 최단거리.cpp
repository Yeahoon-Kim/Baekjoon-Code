#include<vector>
#include <queue>

using namespace std;

bool isIn(int x, int y, int r, int c) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}

int solution(vector<vector<int>> maps) {
    int r = maps.size(), c = maps[0].size();
    queue<pair<pair<int, int>, int>> q;
    int move[5] = {0, 1, 0, -1, 0};
    
    q.push({{0, 0}, 1});
    
    while(!q.empty()) {
        auto [p, dist] = q.front();
        auto [x, y] = p;
        q.pop();
        
        if(!isIn(x, y, r, c) || !maps[x][y] || maps[x][y] == -1) continue;
        
        if(x == r-1 && y == c-1) return dist;
        
        maps[x][y] = -1;
        for(int i = 0; i < 4; i++) {
            q.push({{x+move[i], y+move[i+1]}, dist+1});
        }
    }
    
    return -1;
}