#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, ans=0;
    cin>>n;
    bool a[51]={false};
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        if (a[x]) {
            ans++;
        }
        a[x]=!a[x];
    }
    cout<<ans<<'\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}