#include <bits/stdc++.h>

using namespace std;

void init(void);

int main() {
    init();

    int testCase, column = 0, i, j;
    int sticker[2][100001], DP[2][100001];

    cin >> testCase;
    while(testCase--) {
        cin >> column;

        for(i = 0; i < 2; i++) {
            for(j = 0; j < column; j++) cin >> sticker[i][j];
        }

        DP[0][0] = sticker[0][0];
        DP[1][0] = sticker[1][0];
        DP[0][1] = sticker[0][1] + sticker[0][1];
        DP[1][1] = sticker[0][0] + sticker[1][1];

        for(i = 1; i < column; i++) {
            DP[0][i] = sticker[0][i] + max(DP[1][i - 1], DP[1][i - 2]);
            DP[1][i] = sticker[1][i] + max(DP[0][i - 1], DP[0][i - 2]);
        }

        cout << max(DP[0][column - 1], DP[1][column - 1]) << '\n';
    }

    return 0;
}

void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}