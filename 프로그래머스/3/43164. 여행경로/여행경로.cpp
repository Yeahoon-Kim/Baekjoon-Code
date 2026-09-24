#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<pair<string, bool>>> graph;
vector<string> answer;
bool found = false;

void dfs(const string& current, int ticket_cnt, int target_cnt, vector<string>& path) {
    if(found) return;
    
    if(ticket_cnt == target_cnt) {
        answer = path;
        found = true;
        return;
    }
    
    if(graph.find(current) == graph.end()) return;
    
    for(auto& [next, used] : graph[current]) {
        if(!used) {
            used = true;
            path.push_back(next);
            
            dfs(next, ticket_cnt + 1, target_cnt, path);
            
            path.pop_back();
            used = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    graph.clear();
    answer.clear();
    
    for(const auto& ticket : tickets) {
        graph[ticket[0]].push_back({ticket[1], false});
    }
    
    for(auto& [start, dest] : graph) {
        sort(dest.begin(), dest.end());
    }
    
    vector<string> path = {"ICN"};
    dfs("ICN", 0, tickets.size(), path);
    
    return answer;
}