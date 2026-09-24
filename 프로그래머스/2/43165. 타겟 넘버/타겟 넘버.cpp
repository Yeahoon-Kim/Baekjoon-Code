#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int target, int num = 0, int order = 0) {
    if(numbers.size() == order) return (target == num ? 1 : 0);
    else return dfs(numbers, target, num+numbers[order], order+1)+dfs(numbers, target, num-numbers[order], order+1);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target);
}