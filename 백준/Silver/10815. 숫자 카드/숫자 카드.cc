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

    int cardNum, queryNum, i;
    vector<int> cards;
    vector<int>::iterator it;

    cin >> cardNum;
    cards.resize(cardNum);
    for(auto& a : cards) cin >> a;

    sort(cards.begin(), cards.end());
    cin >> queryNum;

    for(i = 0; i < queryNum; i++) {
        cin >> cardNum;

        it = lower_bound(cards.begin(), cards.end(), cardNum);
        if(it == cards.end() or *it != cardNum) cout << "0 ";
        else cout << "1 ";
    }


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
