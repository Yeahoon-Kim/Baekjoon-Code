#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(
    vector<vector<int>> rectangle, 
    int characterX, int characterY, 
    int itemX, int itemY) {
    
    int answer = 0;
    vector<vector<int>> field(101, vector<int>(101, 0));
    
    for(auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                field[i][j] = -1;
            }
        }
    }
    
    for(auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        
        for(int i = x1 + 1; i < x2; i++) {
            for(int j = y1 + 1; j < y2; j++) {
                field[i][j] = 0;
            }
        }
    }
    
    characterX <<= 1;
    characterY <<= 1;
    itemX <<= 1;
    itemY <<= 1;
    
    queue<pair<int, int>> q;
    int move[5] = {0, 1, 0, -1, 0};
    
    q.push({characterX, characterY});
    field[characterX][characterY] = 0;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nextX = x + move[i];
            int nextY = y + move[i + 1];
            
            if(nextX < 0 || nextX > 100 || nextY < 0 || nextY > 100) continue;
            if(field[nextX][nextY] != -1) continue;
            if(nextX == itemX && nextY == itemY) return (field[x][y] + 1) >> 1;
            
            field[nextX][nextY] = field[x][y] + 1;
            q.push({nextX, nextY});
        }
    }
    
    return -1;
}