#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int a, b, ans = 0;
    cin >> a >> b;
    if (a % 2) {
        cout << "NO\n";
    } else {
        if (b % 2 == 0) {
            cout << "YES\n";
        } else {
            if (a == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}