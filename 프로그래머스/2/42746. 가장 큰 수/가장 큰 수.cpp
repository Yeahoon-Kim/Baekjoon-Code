#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    
    for(auto a : numbers) nums.push_back(to_string(a));
    
    sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    for(auto& a : nums) answer += a;
    
    size_t pos = answer.find_first_not_of('0');
    
    // 모두 '0'이거나 빈 문자열인 경우 "0" 반환
    if (pos == string::npos) return "0";
    
    return answer.substr(pos);
}