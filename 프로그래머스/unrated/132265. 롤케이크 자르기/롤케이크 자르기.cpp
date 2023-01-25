#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> left, right;
    
    for(auto a : topping) right[a]++;
    
    for(auto a : topping) {
        right[a]--, left[a]++;
        if(right[a] == 0) right.erase(a);
        
        if(left.size() == right.size()) answer++;
    }
    
    return answer;
}