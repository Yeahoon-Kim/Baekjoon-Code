#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int max_day = (100 - progresses[0] + speeds[0] - 1) / speeds[0];
    int count = 1;
    
    for(int i = 1; i < progresses.size(); i++) {
        int day = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        
        if(day <= max_day) count++;
        else {
            answer.push_back(count);
            max_day = day;
            count = 1;
        }
    }
    
    answer.push_back(count);
    
    return answer;
}