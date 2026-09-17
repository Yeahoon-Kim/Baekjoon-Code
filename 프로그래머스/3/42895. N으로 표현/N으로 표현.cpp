#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int temp = N;
    unordered_set<int> dp[9];

    dp[1].insert(N);
    if(N == number) return 1;
    
    for(int i = 2; i < 9; i++) {
        temp = 10 * temp + N;
        dp[i].insert(temp);
        
        for(int j = 1; j <= (i>>1); j++) {
            for(auto a : dp[j]) {
                for(auto b : dp[i-j]) {
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(b-a);
                    dp[i].insert(a*b);
                    if(a >= b && b > 0) dp[i].insert(a/b);
                    if(b > a && a > 0) dp[i].insert(b/a);
                }
            }
        }
        if(dp[i].count(number)) return i;
    }
    
    return -1;
}