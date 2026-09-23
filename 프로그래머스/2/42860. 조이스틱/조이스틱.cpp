#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, nameLen = name.size(), min_move = nameLen - 1;
    
    for(int i = 0; i < nameLen; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int next = i + 1;
        while(next < nameLen && name[next] == 'A') next++;
        
        min_move = min({min_move, i * 2 + nameLen - next, 2 * (nameLen - next) + i});
    }
    
    return answer + min_move;
}