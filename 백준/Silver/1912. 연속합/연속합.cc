#include <bits/stdc++.h>

using namespace std;

void init(void);

#define INF (int)1e9

int main() {
    init();

    int arrNum, i, maxNum = -INF, DPValue = 0, arrElement;

    cin >> arrNum;

    for(i = 0; i < arrNum; i++) {
        cin >> arrElement;

        if(!i) maxNum = DPValue = arrElement;
        else {
            DPValue = max(DPValue + arrElement, arrElement);
            maxNum = max(maxNum, DPValue);
        }
    }

    cout << maxNum;

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