#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define MOD (INF + 7)

using namespace std;

void init();

int main() {
    init();

    int pyramidSize, i, j;
    vector<vector<int>> pyramid;
    int maxValue;

    cin >> pyramidSize;
    pyramid.resize(pyramidSize, vector<int>(pyramidSize));

    for(i = 0; i < pyramidSize; i++) {
        for(j = 0; j <= i; j++) {
            cin >> pyramid[i][j];

            if(i == 0) continue;
            if(j == 0) pyramid[i][j] += pyramid[i - 1][j];
            else if(j == i) pyramid[i][j] += pyramid[i - 1][j - 1];
            else pyramid[i][j] += max(pyramid[i - 1][j], pyramid[i - 1][j - 1]);
        }
    }

    maxValue = 0;
    for(j = 0; j < pyramidSize; j++) maxValue = max(maxValue, pyramid[pyramidSize - 1][j]);

    cout << maxValue;

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt+", stdin);
    freopen("output.txt", "wt+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
