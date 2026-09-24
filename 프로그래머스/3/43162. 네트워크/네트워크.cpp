#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using namespace std;

int findRoot(vector<int>& root, int a) {
    if(root[a] == a) return a;
    else return root[a] = findRoot(root, root[a]);
}

void merge(vector<int>& root, vector<int>& height, int a, int b) {
    a = findRoot(root, a);
    b = findRoot(root, b);
    
    if(height[a] > height[b]) swap(a, b);
    else if(height[a] == height[b]) height[b]++;
    
    root[a] = b;
}

bool isSameRoot(vector<int>& root, int a, int b) {
    return findRoot(root, a) == findRoot(root, b);
}

int solution(int n, vector<vector<int>> computers) {
    unordered_set<int> ans;
    
    vector<int> root(n), height(n, 1);
    iota(root.begin(), root.end(), 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(computers[i][j] && !isSameRoot(root, i, j)) merge(root, height, i, j);
        }
    }
    
    for(int i = 0; i < n; i++) ans.insert(findRoot(root, i));
    
    return ans.size();
}