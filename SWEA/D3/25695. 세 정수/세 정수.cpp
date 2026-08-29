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

    ll testCase;

    cin >> testCase;

    while(testCase--) {
        ll x, y, z;

        cin >> x >> y >> z;

        if(x == y && y == z) cout << x << ' ' << y << ' ' << z << '\n';
        else if(x == y && y > z) cout << z << ' ' << x << ' ' << z << '\n';
        else if(y == z && z > x) cout << x << ' ' << x << ' ' << z << '\n';
        else if(z == x && x > y) cout << x << ' ' << y << ' ' << y << '\n';
        else cout << "-1 -1 -1\n";
    }

    return 0;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}