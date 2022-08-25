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

int rightNum(vector<pii>& points, int idx, int pointNum) {
    map<pii, int> m;
    int i, gcdValue, result = 0;

    for(i = 0; i < pointNum; i++) {
        if(i == idx) continue;

        pii vec = {points[i].first - points[idx].first,
                   points[i].second - points[idx].second};

        gcdValue = gcd(vec.first, vec.second);
        if(vec.first > 0 or (!vec.first and vec.second < 0)) gcdValue *= -1;

        vec.first /= gcdValue;
        vec.second /= gcdValue;

        m[vec]++;
    }

    for(auto a : m) {
        auto it = m.find({-a.first.second, a.first.first});
        if(it == m.end()) continue;

        result += a.second * it->second;
    }

    return result;
}

int main() {
    init();

    int pointNum, i, result = 0;
    vector<pii> points;

    cin >> pointNum;
    points.resize(pointNum);
    for(i = 0; i < pointNum; i++) cin >> points[i].first >> points[i].second;

    for(i = 0; i < pointNum; i++) result += rightNum(points, i, pointNum);

    cout << result;

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
