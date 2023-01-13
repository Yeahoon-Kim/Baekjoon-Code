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

    int days, i, j, result = 0;
    pii schedules[16];  // 각 약속의 경과 일과 보수를 각각 저장
    int DP[16];         // 각 날까지 얻은 수익

    cin >> days;
    for(i = 1; i <= days; i++) {
        cin >> schedules[i].first >> schedules[i].second;
        DP[i] = schedules[i].second;    // 해당 날까지 일을 착수해서 벌은 돈
    }

    for(i = 2; i <= days; i++) {
        for(j = 1; j < i; j++) {
            // 이전에 다른 일을 더 해서 수익을 더 낼 수 있는지 조사
            if(i - j >= schedules[j].first) DP[i] = max(schedules[i].second + DP[j], DP[i]);
        }
    }

    for(i = 1; i <= days; i++) {
        if(i + schedules[i].first <= days + 1) result = max(result, DP[i]);
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