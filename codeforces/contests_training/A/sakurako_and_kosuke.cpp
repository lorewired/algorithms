#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, i=1, c=0;
    cin>>n;
    while (c>=-n && c<=n) {
        if (i%2) {
            c-=2*i-1;
        } else {
            c+=2*i-1;
        }
        i++;
    }
    cout<<(i%2?"Kosuke":"Sakurako")<<'\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}