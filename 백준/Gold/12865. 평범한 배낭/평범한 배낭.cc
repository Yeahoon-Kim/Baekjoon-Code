#include <bits/stdc++.h>

using namespace std;

void init(void);

// 각 물건의 가치와 무게에 따른 가방에 든 가치의 총합
int value[101][100001];

int main(void) {
    init();

    // 물건의 무게와 가치
    pair<int, int> stuff[100];
    int count, weight, i, j;

    cin >> count >> weight;

    for(i = 0; i < count; i++) cin >> stuff[i].first >> stuff[i].second;

    for(i = 1; i <= count; i++) {
        for(j = 1; j <= weight; j++) {
            value[i][j] = value[i - 1][j];
            if(j >= stuff[i - 1].first) value[i][j] = max(value[i - 1][j - stuff[i - 1].first] + stuff[i - 1].second, value[i][j]);
        }
    }

    cout << value[count][weight] << '\n';

    return 0;
}

void init(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}