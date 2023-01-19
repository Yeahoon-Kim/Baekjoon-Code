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

using namespace std;

void init();

int main() {
    init();

	int holeNum, tapeLen, i, tapeIdx = -1, answer = 0;
    vector<int> points;

    cin >> holeNum >> tapeLen;

    points.resize(holeNum);
    for(i = 0; i < holeNum; i++) cin >> points[i];
    sort(points.begin(), points.end());

    for(i = 0; i < points.size(); i++) {
        if(tapeIdx == -1) {
            answer++;
            tapeIdx = points[i];
        }
        else if(points[i] - tapeIdx >= tapeLen) {
            tapeIdx = points[i];
            answer++;
        }
    }

    cout << answer << '\n';

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
