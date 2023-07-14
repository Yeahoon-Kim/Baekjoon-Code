#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>

using namespace std;

void init();

int main() {
    init();

    int num, i, j, testCase, before = 2;
    const int MOD = INF + 7;
    ll Cn[5002] = {0, };

    Cn[0] = Cn[1] = 1;

    cin >> testCase;
    while(testCase--) {
        cin >> num;

        for(i = before; i <= num + 1; i++) {
            for(j = 0; j < i; j++) {
                Cn[i] += Cn[j] * Cn[i - 1 - j] % MOD;
                Cn[i] %= MOD;
            }
        }

        cout << Cn[num + 1] << '\n';
        before = max(before, num + 2);
    }

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}