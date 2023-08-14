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

    int coinNum, total, i, j;
    vector<int> coin, DP;

    cin >> coinNum >> total;
    coin.resize(coinNum);
    DP.resize(total + 1);

    for(i = 0; i < coinNum; i++) cin >> coin[i];

    DP[0] = 1;
    for(i = 0; i < coinNum; i++) {
        for(j = coin[i]; j <= total; j++) DP[j] += DP[j - coin[i]];
    }

    cout << DP[total];

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