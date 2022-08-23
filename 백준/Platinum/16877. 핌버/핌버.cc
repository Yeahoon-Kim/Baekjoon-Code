#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define all(x) (x).begin(), (x).end()
#define MOD (INF + 7)

#ifndef ONLINE_JUDGE
#define debug cout << "[DEBUG] "
#define debugv(x) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }
#endif

using namespace std;

void init();

int main() {
    init();

    int dummyNum, i, j, result = 0;
    const int MAX = 3000000;
    vector<int> fibonacci(34), nimbers(MAX + 1), dummy;
    unsigned int stateVar;

    fibonacci[1] = 1;
    for(i = 2; i < 34; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    for(i = 1; i <= MAX; i++) {
        stateVar = 0;

        for(j = 2; fibonacci[j] <= i; j++) stateVar or_eq (1u << nimbers[i - fibonacci[j]]);
        stateVar xor_eq 0xffffffff;
        nimbers[i] = __builtin_ctz(stateVar);
    }

    cin >> dummyNum;
    dummy.resize(dummyNum);
    for(i = 0; i < dummyNum; i++) {
        cin >> dummy[i];
        result xor_eq nimbers[dummy[i]];
    }

    cout << (result ? "koosaga" : "cubelover");

    return 0;
}

void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt+", stdin);
    freopen("output.txt", "wt+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
