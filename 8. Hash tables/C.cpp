#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll s;
    cin >> n >> s;
    ll cnt = 0;

    vector<ll> pref(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> pref[i];
        pref[i] += i > 0 ? pref[i - 1] : 0;
    }

    unordered_map<ll, ll> mp;
    for (int i = 0; i < n + 1; i++) {
        cnt += mp[pref[i] - s];
        mp[pref[i]]++;
    }

    cout << cnt << endl;
}