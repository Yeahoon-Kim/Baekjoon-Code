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

    int arrNum, i, j, result = 0;
    vector<int> arr, DP;

    cin >> arrNum;
    arr.resize(arrNum);
    DP.resize(arrNum);

    for(i = 0; i < arrNum; i++) {
        cin >> arr[i];
        DP[i] = arr[i];

        for(j = 0; j < i; j++) {
            if(arr[i] > arr[j]) DP[i] = max(DP[i], DP[j] + arr[i]);
        }
        result = max(result, DP[i]);
    }

    cout << result;

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