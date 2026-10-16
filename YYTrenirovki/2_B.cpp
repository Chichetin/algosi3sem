#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> c1;
    deque<int> c2;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        c1.push_back(a);
    }
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        c2.push_back(a);
    }
    int turns = 0;
    while (true) {
        if (c1.empty()) {
            cout << "second " << turns << endl;
            return 0;
        }
        if (c2.empty()) {
            cout << "first " << turns << endl;
            return 0;
        }
        if (turns == 1000000) {
            cout << "botva" << endl;
            return 0;
        }

        int a = c1.front(), b = c2.front();
        c1.pop_front();
        c2.pop_front();

        // 0 бьёт 9, в остальных случаях побеждает старшая карта
        bool first_wins = (a == 0 && b == 9) || (a > b && !(a == 9 && b == 0));

        // под низ всегда ложится сначала карта первого игрока, затем второго
        if (first_wins) {
            c1.push_back(a);
            c1.push_back(b);
        } else {
            c2.push_back(a);
            c2.push_back(b);
        }

        turns++;
    }
}
