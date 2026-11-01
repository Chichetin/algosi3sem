#include <bits/stdc++.h>

using namespace std;

using ll = long long;
static const auto great = [](const ll x1, const ll x2) { return x1 > x2; };

int main() {
    priority_queue<ll, vector<ll>, decltype(great)> pq;

    int n;
    cin >> n;
    while (n--) {
        ll d;
        cin >> d;
        pq.push(d);
    }

    ll all_price = 0;

    while (pq.size() > 1) {
        const ll d1 = pq.top();
        pq.pop();
        const ll d2 = pq.top();
        pq.pop();
        pq.push(d1 + d2);
        all_price += d1 + d2;
    }

    cout << all_price << endl;
}
