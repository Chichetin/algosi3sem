#include <bits/stdc++.h>

using namespace std;

static const auto great = [](const int x1, const int x2) { return x1 > x2; };
static const auto lesse = [](const int x1, const int x2) { return x1 < x2; };
static priority_queue<int, vector<int>, decltype(lesse)> lt;
static priority_queue<int, vector<int>, decltype(great)> rt;

static void print_left(priority_queue<int, vector<int>, decltype(lesse)> a) {
    vector<int> output = {};
    while (!a.empty()) {
        output.push_back(a.top());
        a.pop();
    }

    for (const auto i: vector<int>(output.rbegin(), output.rend())) {
        cout << i << " ";
    }
}

static void print_right(priority_queue<int, vector<int>, decltype(great)> a) {
    vector<int> output = {};
    while (!a.empty()) {
        output.push_back(a.top());
        a.pop();
    }

    for (const auto i: output) {
        cout << i << " ";
    }
}

int main() {
    int Q;
    cin >> Q;

    string command;
    int val;
    // Первый add
    Q--;
    cin >> command;
    cin >> val;
    lt.emplace(val);
    // Первый add пройден

    // Общий случай
    unordered_map<string, function<void()> > commands = {
        {
            "ADD", [&]() {
                cin >> val;
                if (val > lt.top()) {
                    rt.emplace(val);
                } else {
                    lt.emplace(val);
                }
                while (lt.size() > rt.size() + 1) {
                    int tmp = lt.top();
                    lt.pop();
                    rt.emplace(tmp);
                }
                while (rt.size() > lt.size()) {
                    int tmp = rt.top();
                    rt.pop();
                    lt.emplace(tmp);
                }
                //cout << "Элемент добавлен: " << val << endl;
                //cout << "lt: ";
                // print_left(lt);
                // cout << "rt: ";
                // print_right(rt);
                // cout << endl;
            }

        },
        {
            "FIND_MEDIAN", [&]() {
                cout <<  lt.top() << endl;
            }
        }
    };
    while (Q--) {
        cin >> command;
        commands[command]();

    }
}
