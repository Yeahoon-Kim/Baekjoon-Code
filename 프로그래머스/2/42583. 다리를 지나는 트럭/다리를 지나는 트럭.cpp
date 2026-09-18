#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;
    int t = 0, current_weight = 0;
    
    for(auto truck : truck_weights) {
        t++;
        
        while(!bridge.empty() && bridge.front().second <= t) {
            current_weight -= bridge.front().first;
            bridge.pop();
        }
        
        while(current_weight + truck > weight || bridge.size() >= bridge_length) {
            t = bridge.front().second;
            current_weight -= bridge.front().first;
            bridge.pop();
        }
        
        current_weight += truck;
        bridge.push({truck, t + bridge_length});
    }
    
    return bridge.back().second;
}