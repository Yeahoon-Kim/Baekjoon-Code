#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0, i;
    
    for(i = 0; i <= d; i += k) answer += (long long)sqrt((long long)d * d - (long long)i * i) / k + 1;
    
    return answer;
}