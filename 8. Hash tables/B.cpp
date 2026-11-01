#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &c: arr) cin >> c;

    unordered_map<ll, ll> mp;
    for_each(arr.begin(), arr.begin() + k, [&](ll x) {
        mp[x]++;
    });

    ll cnt = 0;
    for (auto it : mp) {
        if (it.second >= 1) cnt += 1;
    }
    cout << cnt << endl;

    for (int i = k; i < n; i++) {

        if (++mp[arr[i]] == 1) cnt++;
        if (--mp[arr[i - k]] == 0) cnt--;
        cout << cnt << endl;
    }
}
