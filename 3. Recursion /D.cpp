#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static ll otv = 0;
static int n;

static vector<vector<int>> concatenate(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    vector<vector<int>> c;
    c.insert(c.end(), a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());
    return c;
}

static vector<int> with(const vector<int> &a, const int &b) {
    vector<int> c = a;
    c.push_back(b);
    return c;
}

static vector<vector<int>> recursion(const int i, const int &k, const vector<int> &arr) {
    if (k == 0) {
        otv += 1;
        return {arr};
    }
    if (i == n + 1) {
        return {};
    }

    return concatenate(recursion(i+1, k -1, with(arr, i)), recursion(i + 1, k, arr));

}


int main() {
    int k;
    cin >> n >> k;

    const vector<vector<int>> ans = recursion(1, k, {});

    cout << otv << endl;

    for (auto &x: ans) {
        for (auto &y: x) {
            cout << y << " ";
        }
        printf("\n");
    }

}
