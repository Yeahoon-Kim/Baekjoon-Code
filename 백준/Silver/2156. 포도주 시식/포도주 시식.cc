#include <bits/stdc++.h>

using namespace std;

void init(void);

int main() {
    init();

    int wineNum, i, wine[10001], DP[10002] = {0, };

    cin >> wineNum;
    for(i = 1; i <= wineNum; i++) cin >> wine[i];

    DP[1] = wine[1];
    DP[2] = wine[1] + wine[2];

    for(i = 3; i <= wineNum + 1; i++) DP[i] = max({DP[i - 2] + wine[i], wine[i - 1] + DP[i - 3] + wine[i], DP[i - 1]});

    cout << max(DP[wineNum], DP[wineNum - 1]);

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