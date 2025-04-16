#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, k;
    cin>>n>>k;
    ll ans=0;
    for(int i=k; i<=n; i++) {
        //cout<<pow(i,i)<<'\n';
        ans+=pow(i,i);
    }
    cout<<ans<<'\n';
    cout<<(ans&1?"NO\n":"YES\n");
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}