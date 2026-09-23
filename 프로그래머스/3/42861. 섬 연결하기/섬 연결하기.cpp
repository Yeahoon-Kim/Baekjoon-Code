#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int root[100];
int height[100];

int findRoot(int n) {
    return root[n] = (root[n] == n ? n : findRoot(root[n]));
}

void merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    
    if(height[a] > height[b]) swap(a, b);
    else if(height[a] == height[b]) height[b]++;
    
    root[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        root[i] = i;
        height[i] = 1;
    }
    
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    for(auto& a : costs) {
        if(findRoot(a[0]) != findRoot(a[1])) {
            answer += a[2];
            merge(a[0], a[1]);
        }
    }
    
    for(int i = 1; i < n; i++) {
        if(findRoot(i) != findRoot(0)) return -1;
    }
    
    return answer;
}