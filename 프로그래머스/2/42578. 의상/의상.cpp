#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> m;
    
    
    for(auto& a : clothes) m[a[1]].push_back(a[0]);
    
    for(auto& [key, value] : m) answer *= (value.size()+1);
    
    
    return answer - 1;
}