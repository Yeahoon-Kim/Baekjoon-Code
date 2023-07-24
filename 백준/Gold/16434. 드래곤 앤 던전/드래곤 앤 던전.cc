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

bool canPlay(vector<pll>& rooms, ll heroAttack, ll heroMaxHP) {
    ll heroCurrentHP = heroMaxHP;

    for(auto [attack, health] : rooms) {
        if(attack > 0) {
            heroCurrentHP = min(heroCurrentHP + health, heroMaxHP);
            heroAttack += attack;
        }
        else heroCurrentHP += ((health - 1) / heroAttack) * attack;
        if(heroCurrentHP <= 0) return false;
    }

    return true;
}

int main() {
    init();

    ll roomNum, heroAttack, roomInfo, HP, attack, i, left, right, mid;
    vector<pll> rooms;

    cin >> roomNum >> heroAttack;

    for(i = 0; i < roomNum; i++) {
        cin >> roomInfo >> attack >> HP;
        if(roomInfo == 1) rooms.emplace_back(-attack, HP);
        else rooms.emplace_back(attack, HP);
    }

    left = 0, right = INFLL;
    while(left + 1 < right) {
        mid = (left + right) >> 1;
        if(canPlay(rooms, heroAttack, mid)) right = mid;
        else left = mid;
    }

    cout << right;

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt+", stdin);
    freopen("output.txt", "wt+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
