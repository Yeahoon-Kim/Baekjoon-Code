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

int main() {
    ll testCase;
    cin >> testCase;

    while(testCase--) {
        ll plus, minus;

        cin >> plus >> minus;
        cout << ((plus+minus) >> 1) << ' ' << ((plus - minus) >> 1) << '\n';
    } 

    return 0;
}