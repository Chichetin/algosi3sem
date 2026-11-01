#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct HashTable {
    int cap = 16, sz = 0, del = 0;
    vector<string> keys;
    vector<ll> vals;
    vector<char> st;

    HashTable() : keys(cap), vals(cap), st(cap, 0) {}

    static ull h(const string &s) {
        ull res = 0;
        for (char c : s) res = res * 31 + (c - 'a' + 1);
        return res ^ (res >> 31);
    }

    int find(const string &k) const {
        int i = h(k) & (cap - 1);
        while (st[i]) {
            if (st[i] == 1 && keys[i] == k) return i;
            i = (i + 1) & (cap - 1);
        }
        return -1;
    }

    void rehash() {
        const auto ok = move(keys);
        const auto ov = move(vals);
        const auto os = move(st);
        if ((sz + 1) * 4 > cap) cap *= 2;
        keys.assign(cap, "");
        vals.assign(cap, 0);
        st.assign(cap, 0);
        sz = del = 0;
        for (int i = 0; i < static_cast<int>(os.size()); i++) {
            if (os[i] == 1) put(ok[i], ov[i]);
        }
    }

    void put(const string &k, const ll v) {
        if ((sz + del + 1) * 2 > cap) rehash();
        int i = h(k) & (cap - 1), d = -1;
        while (st[i]) {
            if (st[i] == 1 && keys[i] == k) {
                vals[i] = v;
                return;
            }
            if (st[i] == 2 && d == -1) d = i;
            i = (i + 1) & (cap - 1);
        }
        if (d != -1) {
            i = d;
            del--;
        }
        keys[i] = k;
        vals[i] = v;
        st[i] = 1;
        sz++;
    }

    bool get(const string &k, ll &v) const {
        int i = find(k);
        if (i == -1) return false;
        v = vals[i];
        return true;
    }

    bool erase(const string &k, ll &v) {
        int i = find(k);
        if (i == -1) return false;
        v = vals[i];
        st[i] = 2;
        sz--;
        del++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    HashTable t;
    string cmd, k;
    ll v;

    while (q--) {
        cin >> cmd;
        if (cmd == "put") {
            cin >> k >> v;
            t.put(k, v);
        } else if (cmd == "get") {
            cin >> k;
            if (t.get(k, v)) cout << v << '\n';
            else cout << "Error" << '\n';
        } else if (cmd == "del") {
            cin >> k;
            if (t.erase(k, v)) cout << v << '\n';
            else cout << "Error" << '\n';
        } else {
            cout << t.sz << '\n';
        }
    }
}