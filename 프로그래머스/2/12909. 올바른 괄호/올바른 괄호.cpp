#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int opened = 0;

    for(auto a : s) {
        if(a == '(') opened++;
        else if(a == ')') {
            if(!opened) return false;
            opened--;
        }
    }

    return !opened;
}