#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static ll s;

bool recursion(const ll sum, const int l, const vector<ll> &arr, bool used_any) {
    if (used_any && sum == s ) {
        return true;
    }
    if (l == arr.size()) return false;
    return recursion(sum, l + 1, arr, used_any) || recursion(sum+ arr[l], l + 1, arr, true);
}

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (auto &x: a) cin >> x;

    cin >> s;

    cout << (recursion(0, 0, a, false) ? "Yes" : "No");
}
