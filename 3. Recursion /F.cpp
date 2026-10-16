#include <bits/stdc++.h>

using namespace std;

static vector<vector<int> > lists;

static vector<int> remove_n(const vector<int> &a, const int &i) {
    vector<int> ans;
    ans.insert(ans.end(), a.begin(), a.begin() + i);
    ans.insert(ans.end(), a.begin() + i + 1, a.end());

    return ans;
}

static vector<int> with(const vector<int> &a, const int &x) {
    vector<int> b = a;
    b.push_back(x);
    return b;
}

bool ok(const vector<int> &arr, const int c) {
    const int r = arr.size();
    for (int i = 0; i < r; i++) {
        if (abs(i - r) == abs(arr[i] - c)) {
            return false;
            break;
        }
    }

    return true;
}

static void recursion(const vector<int> &options, const vector<int> &itog) {
    for (int i = 0; i < options.size(); i++) {
        if (ok(itog, options[i])) {
            recursion(remove_n(options, i), with(itog, options[i]));
        }
    }
    if (options.empty()) {
        lists.push_back(itog);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(i + 1);
    }

    //for (auto &c : remove_n(arr, 0)) cout << c << endl;
    recursion(arr, vector<int>());

    cout << lists.size() << endl;
    for (auto &c: lists) {
        for (const auto &it: c) {
            printf("%d ", it);
        }
        cout << endl;
    }
}
