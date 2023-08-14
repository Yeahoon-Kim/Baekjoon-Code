#include <bits/stdc++.h>

using namespace std;

void init(void);

typedef long long int ll;

int numbers[101];
ll DP[101][21];

int main() {
    init();

    int numberNum, i, j;

    cin >> numberNum;

    for(i = 0; i < numberNum; i++) cin >> numbers[i];

    DP[0][numbers[0]] = 1;

    for(i = 1; i < numberNum - 1; i++) {
        for(j = 0; j <= 20; j++) {
            if(DP[i - 1][j] != 0) {
                if(j - numbers[i] >= 0) DP[i][j - numbers[i]] += DP[i - 1][j];
                if(j + numbers[i] <= 20) DP[i][j + numbers[i]] += DP[i - 1][j];
            }
        }
    }

    cout << DP[numberNum - 2][numbers[numberNum - 1]];
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