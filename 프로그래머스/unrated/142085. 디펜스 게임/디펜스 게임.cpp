#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int enemyNum = 0, left, right, mid, i, partSum;
    vector<int> chance, partArr;
    
    left = 0;
    right = enemy.size();
    
    while(left + 1 < right) {
        mid = (left + right) >> 1;
        
        partArr.assign(mid, 0);
        copy(enemy.begin(), enemy.begin() + mid, partArr.begin());
        sort(partArr.begin(), partArr.end());
        
        partSum = 0;
        for(i = 0; i < mid - k; i++) partSum += partArr[i];
        
        if(partSum > n) right = mid;
        else left = mid;
    }
    
    
    
    return left;
}