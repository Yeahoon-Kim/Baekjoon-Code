#include <bits/stdc++.h>

#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ll long long int

using namespace std;

void init(void);

int table[1025][1025];
ll DP[1025][1025];

int main(void) {
    init();

    int fieldSize, queryNum, i, j;
    pii start, end;
    ll partSum, result;

    cin >> fieldSize >> queryNum;

    for(i = 1; i <= fieldSize; i++) {
        partSum = 0;

        for(j = 1; j <= fieldSize; j++) {
            cin >> table[i][j];

            partSum += table[i][j];
            DP[i][j] = DP[i - 1][j] + partSum;
        }
    }

    for(i = 0; i < queryNum; i++) {
        cin >> start.first >> start.second >> end.first >> end.second;

        result = DP[end.first][end.second] + DP[start.first - 1][start.second - 1];
        result -= DP[end.first][start.second - 1] + DP[start.first - 1][end.second];

        cout << result << '\n';
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
