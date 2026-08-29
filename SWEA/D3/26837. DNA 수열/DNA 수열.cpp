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
        ll dnaLen, ans = 0;
        string dna;

        cin >> dnaLen >> dna;

        vector<pll> arr(dnaLen+1, pll(0, 0));

        for(ll i = 0; i < dnaLen; i++) {
            if (i) {
                arr[i+1].first = arr[i].first;
                arr[i+1].second = arr[i].second;
            }
            if(dna[i] == 'A') arr[i+1].first++;
            if(dna[i] == 'T') arr[i+1].first--;
            if(dna[i] == 'G') arr[i+1].second++;
            if(dna[i] == 'C') arr[i+1].second--;
        }

        for(ll i = 0; i < dnaLen; i++) {
            for(ll j = i+1; j<dnaLen+1; j++) {
                if(arr[j].first - arr[i].first == 0 && arr[j].second - arr[i].second == 0) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}