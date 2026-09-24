#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int left = 0, right = 1e9+1, mid, serial, stone;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    while(left + 1 < right) {
        mid = (left + right) >> 1;
        serial = 1;
        stone = 0;
        
        for(int i = 1; i < rocks.size(); i++) {
            if(rocks[i] - rocks[i-serial] < mid) {
                serial++, stone++;
            }
            else serial = 1;
        }
        
        if(stone > n) right = mid;
        else left = mid;
    }
    
    return left;
}