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

    int i, j, left, right, primeSum, target, result;
    vector<int> primes;
    bitset<4000001> isPrime;

    cin >> target;

    isPrime.set();

    isPrime[0] = isPrime[1] = false;
    for(i = 3; i <= 2000; i += 2) {
        if(not isPrime[i]) continue;

        for(j = 2 * i; j <= 4000000; j += i) isPrime[j] = false;
    }

    primes.push_back(2);
    for(i = 3; i <= 4000000; i += 2) if(isPrime[i]) primes.push_back(i);

    left = right = primeSum = result = 0;
    while(right <= primes.size()) {
        if(target > primeSum) primeSum += primes[right++];
        else if(target < primeSum) primeSum -= primes[left++];
        else {
            result++;

            primeSum -= primes[left++];
            primeSum += primes[right++];
        }
    }

    cout << result;

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
