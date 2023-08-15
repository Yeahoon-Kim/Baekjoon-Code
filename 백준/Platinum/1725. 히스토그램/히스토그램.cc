#include <bits/stdc++.h>

#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ll long long int

using namespace std;

void init(void);

int main(void) {
    init();

    vector<int> histograms;
    stack<int> s;
    int poleNum, i, result = 0, check;

    cin >> poleNum;
    histograms.resize(poleNum + 2);
    for(i = 1; i <= poleNum; i++) cin >> histograms[i];

    s.push(0);
    for(i = 1; i <= poleNum + 1; i++) {
        while(!s.empty() and histograms[s.top()] > histograms[i]) {
            check = s.top();

            s.pop();
            result = max(result, histograms[check] * (i - s.top() - 1));
        }

        s.push(i);
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