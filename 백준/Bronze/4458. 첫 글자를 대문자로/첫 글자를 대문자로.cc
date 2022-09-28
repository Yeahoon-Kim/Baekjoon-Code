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

#ifndef ONLINE_JUDGE
#define debug cout << "[DEBUG] "
#define debugv(x) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }
#endif

using namespace std;

void init();

int main() {
    init();

    int testCase;
    string str;

    cin >> testCase;
    getline(cin, str);
    while(testCase--) {
        getline(cin, str);
        if(islower(str.front())) *str.begin() = toupper(str.front());

        cout << str << '\n';
    }


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
