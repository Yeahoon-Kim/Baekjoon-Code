#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto& a : commands) {
        vector<int> temp(array.begin()+a[0]-1, array.begin()+a[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[a[2]-1]);
    }
    
    return answer;
}