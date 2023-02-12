#include <bits/stdc++.h>

using namespace std;

void init(void);

vector<int> houseList;

bool isPossible(int minLength, int modemNum) {
    vector<int>::iterator before = houseList.begin();
    int possibleModemNum = 1;

    for(auto it = houseList.begin(); it != houseList.end(); it++) {
        if(*it - *before >= minLength) {
           before = it;
           possibleModemNum++;
        }
    }

    if(possibleModemNum >= modemNum) return true;
    else return false;
}

int main() {
    init();

    int modemNum, houseNum, i, low, high, mid, result;

    cin >> houseNum >> modemNum;
    houseList.resize(houseNum);

    cin >> houseList[0];
    for(i = 1; i < houseNum; i++) cin >> houseList[i];
    sort(houseList.begin(), houseList.end());

    result = low = 1;
    high = *houseList.rbegin() - *houseList.begin();

    while(low <= high) {
        mid = (low + high) / 2;

        if(isPossible(mid, modemNum)) {
            result = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << result;
}

void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}