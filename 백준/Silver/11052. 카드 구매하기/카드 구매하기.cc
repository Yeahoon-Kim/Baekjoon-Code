#include <bits/stdc++.h>

using namespace std;

void init(void);

int main() {
    init();

    int cardNum, i, j;
    int cost[1001];

    cin >> cardNum;
    for(i = 1; i <= cardNum; i++) cin >> cost[i];

     for(i = 1; i <= cardNum; i++) {
        for(j = 1; j < i; j++) {
            cost[i] = max(cost[i], cost[i - j] + cost[j]);
        }
     }

    cout << cost[cardNum];

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