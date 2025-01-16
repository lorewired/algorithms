#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k+1,0);
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        a[x]+=y;
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans=0;
    for(int i=0; i<n; i++) if(i<=k) ans+=a[i];
    cout<<ans<<'\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}