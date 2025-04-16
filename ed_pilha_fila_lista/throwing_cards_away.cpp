#include <iostream>
#include <string>
#include <queue>
using namespace std;

signed main() {
    int n;
    while (cin >> n && n != 0) {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        cout << "Discarded cards: ";
        while (q.size() > 1) {
            cout << q.front() << (q.size() - 1 == 1 ? "\n" : ", ");
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << "Remaining card: " << q.front() << '\n';
    }
    return 0;
}