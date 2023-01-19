#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void init();

int main() {
    init();
    
    int n, m, a, b;
    cin >> n >> m;

    vector<int> v(n + 1), sum(n + 1);

    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
    }

    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << '\n';
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


