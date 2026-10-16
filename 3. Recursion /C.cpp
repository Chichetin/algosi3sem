#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static ll s;

vector<ll> with(const vector<ll> &v, const ll &x) {
    vector<ll> res = v;
    res.push_back(x);
    return res;
}

bool recursion(const ll &sum, const int &l, const vector<ll> &arr, const bool &used_any, const vector<ll> &used) {
    if (used_any && sum == s) {
        cout << "Yes" << endl;
        cout << used.size() << endl;
        for (const auto& c : used) cout << c << " ";
        return true;
    }
    if (l == arr.size()) return false;
    return recursion(sum + arr[l], l + 1, arr, true, with(used, arr[l]))
           || recursion(sum, l + 1, arr, used_any, used);
}

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (auto &x: a) cin >> x;

    cin >> s;

    if (!recursion(0, 0, a, false, vector<ll>(0)))
        cout << "No" << endl;
}
