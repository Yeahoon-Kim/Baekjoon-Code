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
    ll jumpUnit, jumpSum, left, right, mid, midSum;

    cin >> testCase;
    while(testCase--) {
        cin >> jumpSum >> jumpUnit;
        jumpSum--;

        left = 0, right = 5000;
        while(left + 1 < right) {
            mid = (left + right) >> 1;
            midSum = mid * (mid + 1) >> 1;

            if(midSum * jumpUnit <= jumpSum) left = mid;
            else right = mid;
        }

        midSum = left * (left + 1) >> 1;

        if(left & 1) {
            mid = ((left >> 1) + 1) * jumpUnit;
            cout << mid - jumpSum + midSum * jumpUnit << " L\n";
        }

        else {
            mid = -(left >> 1) * jumpUnit;
            cout << mid + jumpSum - midSum * jumpUnit << " R\n";
        }
    }

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
