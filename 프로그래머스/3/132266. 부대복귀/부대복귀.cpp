#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> dist(n+1, -1);
    vector<vector<int>> graph(n+1);
    queue<int> q;
    
    for(auto& road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    dist[destination] = 0;
    q.push(destination);
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        for(auto& a : graph[current]) {
            if(dist[a] != -1) continue;
            dist[a] = dist[current] + 1;
            q.push(a);
        }
    }
    
    for(auto a : sources) answer.push_back(dist[a]);
    
    return answer;
}