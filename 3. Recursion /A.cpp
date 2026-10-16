#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static ll m;
static vector<ll> memo;

ll fin(ll n) {
    if (memo[n] != -1) return memo[n];
    memo[n] = (memo[n - 1] != -1 ? memo[n - 1] : fin(n - 1)) + (memo[n - 2] != -1 ? memo[n - 2] : fin(n - 2)) % m;
    return memo[n];
}


int main() {
    ll n;
    cin >> n >> m;

    memo.assign(n + 1, -1);
    memo[0] = 1;
    memo[1] = 1;

    cout << fin(n) % m << endl;
}
