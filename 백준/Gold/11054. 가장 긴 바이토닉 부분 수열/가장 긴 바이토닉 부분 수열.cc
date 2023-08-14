#include <bits/stdc++.h>

using namespace std;

void init(void);



int main() {
    init();

    int arrNum, arr[1000], DP[2][1000], i, j, invI, result = 0;

    cin >> arrNum;
    for(i = 0; i < arrNum; i++) cin >> arr[i];

    for(i = 0; i < arrNum; i++) {
        invI = arrNum - 1 - i;
        DP[0][i] = 1;
        DP[1][invI] = 1;

        for(j = 0; j < i; j++) if(arr[i] > arr[j]) DP[0][i] = max(DP[0][i], DP[0][j] + 1);
        for(j = arrNum - 1; j > invI; j--) if(arr[invI] > arr[j]) DP[1][invI] = max(DP[1][invI], DP[1][j] + 1);
    }

    for(i = 0; i < arrNum; i++) result = max(result, DP[0][i] + DP[1][i] - 1);

    cout << result;

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