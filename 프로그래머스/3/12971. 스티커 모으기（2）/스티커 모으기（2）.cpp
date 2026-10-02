#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker) {
    vector<int> arr;
    
    int n = sticker.size();
    
    if(n == 1) return sticker[0];
    
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);
    
    // 0번 스티커 뜯음
    dp1[0] = sticker[0];
    dp1[1] = 0;
    dp1[2] = sticker[0] + sticker[2];
    for(int i = 3; i < n - 1; i++) dp1[i] = max(dp1[i-2], dp1[i-3]) + sticker[i];
    
    // 0번 스티커 안 뜯음
    dp2[0] = 0;
    dp2[1] = sticker[1];
    dp2[2] = sticker[2];
    for(int i = 3; i < n; i++) dp2[i] = max(dp2[i-2], dp2[i-3]) + sticker[i];
    
    return max({dp1[n-2], dp1[n-3], dp2[n-1], dp2[n-2]});
}