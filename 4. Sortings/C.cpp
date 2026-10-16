#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    if (arr[0] == "0") {
        cout << "0\n";
        return 0;
    }

    for (const auto& s : arr) {
        cout << s;
    }
    cout << '\n';
}
