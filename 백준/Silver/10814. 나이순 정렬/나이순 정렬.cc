#include <bits/stdc++.h>

using namespace std;

bool compareAge(pair<int, string> a, pair<int, string> b) {
    return (a.first < b.first);
}

int main(void) {
    int count;
    vector<pair<int, string>> members;
    pair<int, string> inputMember;

    cin >> count;

    for(; count; count--) {
        cin >> inputMember.first >> inputMember.second;

        members.push_back(inputMember);
    }

    stable_sort(members.begin(), members.end(), compareAge);

    for(auto it = members.begin(); it != members.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }

    return 0;
}