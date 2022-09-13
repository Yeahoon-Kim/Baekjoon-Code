#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define MOD (INF + 7)

using namespace std;

void init();

int main() {
    init();

    int gameNum, winNum, left, right, mid;
    ll winPercent, newPercent;

    cin >> gameNum >> winNum;
    winPercent = (ll)winNum * 100 / gameNum;

    if(winPercent >= 99) {
        cout << -1 << '\n';
        return 0;
    }

    left = 0, right = INF;
    while(left + 1 < right) {
        mid = (left + right) >> 1;

        newPercent = (ll)(winNum + mid) * 100 / (gameNum + mid);
        if(winPercent < newPercent) right = mid;
        else left = mid;
    }

    cout << right << '\n';

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt+", stdin);
    freopen("output.txt", "wt+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
