#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<string> split(const string& str, char delimiter=' ') {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    
    while(getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}


vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    
    for(auto& operation : operations) {
        vector<string> inst = split(operation);
        
        if(inst[0] == "I") ms.insert(stoi(inst[1]));
        else {
            if(ms.empty()) continue;
            if(stoi(inst[1]) == 1) ms.erase(prev(ms.end()));
            else ms.erase(ms.begin());
        }
    }
    
    return (ms.empty() ? vector<int>({0, 0}) : vector<int>({*ms.rbegin(), *ms.begin()}));
}