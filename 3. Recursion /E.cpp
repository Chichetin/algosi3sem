#include <bits/stdc++.h>

using namespace std;

static long long k = 0;
static vector<string> lines;

void recursion(int n, int main, int target, int auxilary) {
    if (n == 1) {
       lines.push_back(format("{} {} {}\n", 1, main, target));
        k++;
        return;
    }

    recursion(n - 1, main, auxilary, target);

    lines.push_back(format("{} {} {}\n", n, main, target));
    k++;

    recursion(n - 1, auxilary, target, main);
}

int main() {
    int n;
    cin >> n;

    recursion(n, 1, 3, 2);

    cout << k << endl;

    for (auto &c: lines) {
        cout << c;
    }
}
