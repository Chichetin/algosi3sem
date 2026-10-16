#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        arr[i][1] = i + 1;
    }
    sort(arr.begin(), arr.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[0] < b[0];
    });

    ll search;
    cin >> search;

    for (int i = 0, j = n - 1; i < j;) {
        if (arr[i][0] + arr[j][0] == search) {
            if (arr[i][1] < arr[j][1])
                cout << arr[i][1] << " " << arr[j][1] << endl;
            else
                cout << arr[j][1] << " " << arr[i][1] << endl;
            return 0;
        } else if (arr[i][0] + arr[j][0] < search) i += 1;
        else j -= 1;
    }

    cout << -1;
}
