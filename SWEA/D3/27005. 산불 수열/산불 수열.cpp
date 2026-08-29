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

    int testCase;
    vector<int> arr(1001, 0);

    for(int i = 0; i < 1001; i++) {
        vector<bool> impossible(10000, false);
        if(i < 2) arr[i] = 1;
        else {
            for(int k = 1; k <= i / 2; k++) {
                int temp = 2 * arr[i-k]-arr[i-2*k];
                if(temp > 0) impossible[temp] = true;
            }
            for(int k = 1; k < 10000; k++) {
                if(not impossible[k]) {
                    arr[i] = k;
                    break;
                }
            }
        }
    }

    cin >> testCase;
    while (testCase--) {
        ll n;
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}