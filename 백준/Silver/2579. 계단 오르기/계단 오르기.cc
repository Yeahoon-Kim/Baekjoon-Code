#include <bits/stdc++.h>

using namespace std;

void init(void);

#define INF 1e9
#define INFLL 4e18

int main(void) {
    init();

    // maxSum의 경우 i번째 값이 i - 1번째 계단까지의 최댓값을 의미한다.
    int level, arr[301], maxSum[302], i;

    cin >> level;
    for (i = 1; i <= level; i++) cin >> arr[i];

    maxSum[0] = maxSum[1] = 0;
    maxSum[2] = arr[1];
    for (i = 3; i <= level + 1; i++) {
        maxSum[i] = max(maxSum[i - 2] + arr[i - 1], maxSum[i - 3] + arr[i - 2] + arr[i - 1]);
    }

    cout << maxSum[level + 1] << '\n';

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