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

    pii A, B, C;
    vector<double> line(3);

    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    if((B.first - A.first) * (C.second - B.second) ==
       (C.first - B.first) * (B.second - A.second)) {
        cout << -1;
        return 0;
    }

    line[0] = hypot(C.first - B.first, C.second - B.second);
    line[1] = hypot(A.first - C.first, A.second - C.second);
    line[2] = hypot(B.first - A.first, B.second - A.second);
    sort(all(line));

    cout << fixed << setprecision(9) << 2 * (line[2] - line[0]);

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
