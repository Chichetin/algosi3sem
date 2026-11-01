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

void siftUp(const int i) {
    if (i == 0) return;
    if (a[i] < a[(i - 1) / 2]) {
        const int tmp = a[i];
        a[i] = a[(i - 1) / 2];
        a[(i - 1) / 2] = tmp;
        siftUp((i - 1) / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    a.resize(n);
    int n_all = 0;
    int n_i;
    while (k-- > 0) {
        cin >> n_i;
        const int n_prev = n_all;
        n_all += n_i;

        a.resize(n_all);

        for (int i = 0; i < n_i; i++) {
            int r;
            cin >> r;
            a[n_prev + i] = r;
            siftUp(n_prev + i);
        }
    }


    int sz = a.size();
    while (sz > 0) {
        cout << a[0] << ' ';
        a[0] = a[--sz];
        siftDown(0, sz);
    }
}
