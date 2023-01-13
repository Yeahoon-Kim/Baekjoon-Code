#include <bits/stdc++.h>

using namespace std;

void init(void);

int queenPlace[15];
int possibleNum;

bool isPossible(int level) {
    for(int i = 0; i < level; i++) {
        if(queenPlace[i] == queenPlace[level]) return false;
        if(level - i == abs(queenPlace[i] - queenPlace[level])) return false;
    }

    return true;
}

void queenDFS(int scale, int level = 0) {
    if(level == scale) possibleNum++;

    else {
        for(int i = 0; i < scale; i++) {
            queenPlace[level] = i;
            if(isPossible(level)) queenDFS(scale, level + 1);
        }
    }
}

int main() {
    init();

    int N;

    cin >> N;

    queenDFS(N);
    cout << possibleNum;

    return 0;
}

void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}