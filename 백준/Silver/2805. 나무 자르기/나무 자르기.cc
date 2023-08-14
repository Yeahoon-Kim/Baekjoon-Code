#include <bits/stdc++.h>

#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ll long long int

using namespace std;

void init(void);

bool isPossible(vector<int>& woods, int length, int need) {
    ll part = 0;

    for(auto oneWood : woods) {
        part += (oneWood > length ? oneWood - length : 0);
    }

    if(part >= need) return true;
    else return false;
}

int main(void) {
    init();

    vector<int> woods;
    int woodNum, i, left, right, mid, result, need;

    cin >> woodNum >> need;
    woods.resize(woodNum);
    for(i = 0; i < woodNum; i++) cin >> woods[i];

    left = 0;
    right = INF << 1;

    while(left < right) {
        mid = (left + right) >> 1;

        if(isPossible(woods, mid, need)) {
            result = mid;
            left = mid + 1;
        }
        else right = mid;
    }

    cout << result;

    return 0;
}

void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
