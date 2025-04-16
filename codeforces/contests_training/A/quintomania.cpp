#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, ant=-1, perf=1;
    cin>>n;
    while (n--) {
        int x;
        cin>>x;
        if (ant!=-1) {
            int diff=max(x,ant)-min(x,ant);
            if (diff!=5 && diff!=7) {
                perf=0;
            }
        }
        ant=x;
    }
    cout<<(perf?"YES":"NO")<<'\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}