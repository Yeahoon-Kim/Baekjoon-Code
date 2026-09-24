#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

using Point = pair<int, int>;
using Shape = vector<Point>;

bool isIn(int x, int y, int r, int c) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

bool isIn(Point p, int r, int c) {
    return isIn(p.first, p.second, r, c);
}

Shape normalize(const Shape& shape) {
    pair<int, int> minP = {INF, INF};
    
    for(const auto& point : shape) {
        minP.first = min(minP.first, point.first);
        minP.second = min(minP.second, point.second);
    }
    
    Shape res;
    for(const auto& point : shape) {
        res.push_back({point.first - minP.first, point.second - minP.second});
    }
    sort(res.begin(), res.end());
    
    return res;
}

Shape extract(vector<vector<int>>& board, Point p, int buffer) {
    queue<Point> q;
    Shape res;
    int move[5] = {0, 1, 0, -1, 0};
    
    board[p.first][p.second] = buffer;
    q.push(p);
    
    while(!q.empty()) {
        Point current = q.front();
        q.pop();
        
        res.push_back(current);
        
        for(int i = 0; i < 4; i++) {
            Point next = {current.first+move[i], current.second+move[i+1]};
            if(!isIn(next, board.size(), board[0].size())) continue;
            if(board[next.first][next.second] == buffer) continue;
            board[next.first][next.second] = buffer;
            q.push(next);
        }
    }
    
    return res;
}

Shape rotate(const Shape& block) {
    Shape res;
    
    for(auto& p : block) {
        res.push_back({p.second, -p.first});
    }
    
    return normalize(res);
}

bool match(const Shape& space, const Shape& block) {
    Shape b = block;
    Shape s = space;
    
    if(b.size() != s.size()) return false;
    
    for(int i = 0; i < 4; i++) {
        if(b == s) return true;
        b = rotate(b);
    }
    
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size(), answer = 0;
    vector<Shape> spaces;
    vector<Shape> blocks;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(game_board[i][j] == 0) {
                spaces.push_back(normalize(extract(game_board, {i, j}, 1)));
            }
            if(table[i][j] == 1) {
                blocks.push_back(normalize(extract(table, {i, j}, 0)));
            }
        }
    }
    
    vector<bool> used_block(blocks.size());
    
    for(Shape& s : spaces) {
        for(int i = 0; i < blocks.size(); i++) {
            if(used_block[i]) continue;
            if(match(s, blocks[i])) {
                used_block[i] = true;
                break;
            }
        }
    }
    
    for(int i = 0; i < blocks.size(); i++) if(used_block[i]) answer += blocks[i].size(); 
    
    return answer;
}