#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> arr[9];
    int answer = 0, len = priorities.size();
    
    for(int i = 0; i < len; i++) arr[priorities[i]-1].push_back(i);
    
    int idx = 0;
    for(int i = 8; i >= 0; i--) {
        if(arr[i].empty()) continue;
        
        if(find(arr[i].begin(), arr[i].end(), location) != arr[i].end()) {
            for(auto& a : arr[i]) if(idx > a) a += len;
            if(idx > location) location += len;
            
            sort(arr[i].begin(), arr[i].end());
            answer += find(arr[i].begin(), arr[i].end(), location) - arr[i].begin() + 1;
            break;
        }
        else {
            answer += arr[i].size();
            auto it = lower_bound(arr[i].begin(), arr[i].end(), idx);
            idx = (it == arr[i].begin() ? arr[i].back() : *(it - 1));
        }
        
    }
    
    return answer;
}