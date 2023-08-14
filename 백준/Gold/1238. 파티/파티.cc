#include <bits/stdc++.h>

#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ll long long int

using namespace std;

void init(void);

vector<pii> graph[1001], tGraph[1001];
int distCome[1001], distLeave[1001];

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

int DijkstraProcessing(int partyTown, int townNum) {
    priority_queue<int, vector<int>, greater<>> pq;
    int current, maxValue = 0;

    fill_n(distCome + 1, townNum, INF);
    fill_n(distLeave + 1, townNum, INF);
    distCome[partyTown] = distLeave[partyTown] = 0;

     // to partyTown
    pq.push(partyTown);
    while(!pq.empty()) {
        current = pq.top();
        pq.pop();

        for(auto next : tGraph[current]) {
            if(distCome[current] + next.second < distCome[next.first]) {
                distCome[next.first] = distCome[current] + next.second;
                pq.push(next.first);
            }
        }
    }

     // from partyTown
    pq.push(partyTown);
    while(!pq.empty()) {
        current = pq.top();
        pq.pop();

        for(auto next : graph[current]) {
            if(distLeave[current] + next.second < distLeave[next.first]) {
                distLeave[next.first] = distLeave[current] + next.second;
                pq.push(next.first);
            }
        }
    }

    for(int i = 1; i <= townNum; i++) {
        if(i != partyTown) maxValue = max(maxValue, distCome[i] + distLeave[i]);
    }

    return maxValue;
}

int main(void) {
    init();

    int townNum, roadNum, partyTown, fromTown, toTown, distance, i, result;

    cin >> townNum >> roadNum >> partyTown;
    for(i = 0; i < roadNum; i++) {
        cin >> fromTown >> toTown >> distance;

        graph[fromTown].emplace_back(toTown, distance);
        tGraph[toTown].emplace_back(fromTown, distance);
    }

    result = DijkstraProcessing(partyTown, townNum);

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