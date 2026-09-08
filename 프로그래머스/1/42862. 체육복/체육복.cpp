#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size(), a = 0, b = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    while(a < lost.size() && b < reserve.size()) {
        if(lost[a] == reserve[b]) {
            lost[a] = reserve[b] = -1;
            answer++;
            a++;
            b++;
        }
        else if(lost[a] > reserve[b]) b++;
        else a++;
    }
    
    a = b = 0;
    while(a < lost.size() && b < reserve.size()) {
        if(lost[a] == -1) {a++; continue;}
        if(reserve[b] == -1) {b++; continue;}
        if(abs(lost[a] - reserve[b]) <= 1) {
            answer++;
            a++;
            b++;
        }
        else if(lost[a] > reserve[b]) b++;
        else a++;
    }
    
    return answer;
}