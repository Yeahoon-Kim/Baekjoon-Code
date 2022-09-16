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

    int liquidNum, left, right, diff;
    vector<int> liquids;
    pii result = {INF, INF};

    cin >> liquidNum;
    liquids.resize(liquidNum);
    for(auto& a : liquids) cin >> a;

    sort(liquids.begin(), liquids.end());

    left = 0, right = liquidNum - 1;
    while(left < right) {
        diff = liquids[left] + liquids[right];
        if(abs(diff) < abs(result.first + result.second)) result = {liquids[left], liquids[right]};

        if(!diff) break;
        else if(diff > 0) right--;
        else left++;
    }

    cout << result.first << ' ' << result.second;

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
