#include <bits/stdc++.h>
using namespace std;

static int n, k;
static vector<int> a;

void siftDown(int i, int sz) {
    while (true) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < sz && a[l] < a[m]) m = l;
        if (r < sz && a[r] < a[m]) m = r;
        if (m == i) return;
        swap(a[i], a[m]);
        i = m;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    for (auto& x : a) cin >> x;

    for (int i = n / 2 - 1; i >= 0; --i) siftDown(i, n);

    int sz = n;
    for (int t = 0; t < k - 1; ++t) {
        a[0] = a[sz - 1];
        --sz;
        siftDown(0, sz);
    }

    cout << a[0] << '\n';
}