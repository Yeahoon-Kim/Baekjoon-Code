#include <bits/stdc++.h>

using namespace std;

void init(void);

int value[1000001];

int main(void) {
    int num;
    
    init();
    
    cin >> num;
    value[1] = 0;
    
    for(int i = 2; i <= num; i++) {
        value[i] = value[i - 1] + 1;
        if(!(i % 2) && value[i] > value[i / 2] + 1) value[i] = value[i / 2] + 1;
        if(!(i % 3) && value[i] > value[i / 3] + 1) value[i] = value[i / 3] + 1;
    }

    cout << value[num] << '\n';
}

void init(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}