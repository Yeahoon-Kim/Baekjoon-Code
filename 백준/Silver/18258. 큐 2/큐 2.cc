#include <bits/stdc++.h>

#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ll long long int

using namespace std;

void init(void);

int main(void) {
    init();

    deque<int> dq;
    string opcode;
    int inputData, opcodeNum;

    cin >> opcodeNum;
    while(opcodeNum--) {
        cin >> opcode;

        if(opcode == "push") {
            cin >> inputData;
            dq.push_back(inputData);
        }
        else if(opcode == "pop") {
            if(dq.empty()) {
                cout << -1 << '\n';
                continue;
            }

            cout << dq.front() << '\n';
            dq.pop_front();
        }
        else if(opcode == "size") {
            cout << dq.size() << '\n';
        }
        else if(opcode == "empty") {
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
        else if(opcode == "front") {
            if(dq.empty()) {
                cout << -1 << '\n';
                continue;
            }

            cout << dq.front() << '\n';
        }
        else {
            if(dq.empty()) {
                cout << -1 << '\n';
                continue;
            }

            cout << dq.back() << '\n';
        }
    }

    return 0;
}


void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
