#include <string>
#include <vector>

#define INFLL 1e18

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 0, right = INFLL, mid, people;
    
    while(left + 1 < right) {
        mid = (left + right) >> 1;
        people = 0;
        
        for(const int& t : times) people += (mid / t);
        
        if(people < n) left = mid;
        else right = mid;
    }
    
    return right;
}