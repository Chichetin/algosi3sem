#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Result {
public:
    ll solved = 0;
    ll shtraf = 0;
    string login;

    Result() = default;

    Result(const ll solved, const ll shtraf, const string &login)
        : solved(solved), shtraf(shtraf), login(login) {
    }
};

int main() {
    int n;
    cin >> n;

    vector<Result> students(n);
    for (auto &s: students) {
        cin >> s.login;
        cin >> s.solved;
        cin >> s.shtraf;
        s.shtraf *= -1;
    }

    sort(students.begin(), students.end(), [](const Result &r1, const Result &r2) {
        if (r1.solved != r2.solved) return r1.solved > r2.solved;
        if (r1.shtraf != r2.shtraf) return r1.shtraf > r2.shtraf;
        return r1.login < r2.login;
    });

    for (const auto &s: students) {
        cout << s.login << "\n";
    }
}
