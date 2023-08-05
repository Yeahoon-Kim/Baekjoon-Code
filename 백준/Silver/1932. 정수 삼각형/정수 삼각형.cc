#include <bits/stdc++.h>

using namespace std;

void init(void);

#define INF 1e9
#define INFLL 4e18

int pyramid[501][501];

int main(void) {
    init();

    int pyramidSize, i, j, maxSum = 0;

    cin >> pyramidSize;
    for (i = 0; i < pyramidSize; i++) {
        for(j = 0; j <= i; j++) cin >> pyramid[i][j];
    }

    for(i = 1; i < pyramidSize; i++) {
        for(j = 0; j <= i; j++) {
            if(j == 0) pyramid[i][j] += pyramid[i - 1][j];
            else if(j == i) pyramid[i][j] += pyramid[i - 1][j - 1];
            else pyramid[i][j] += max(pyramid[i - 1][j], pyramid[i - 1][j - 1]);
        }
    }

    for(i = 0; i < pyramidSize; i++) {
        maxSum = max(maxSum, pyramid[pyramidSize - 1][i]);
    }

    cout << maxSum;

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