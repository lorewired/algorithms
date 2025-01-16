#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, x, y, ans=0;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int &i : a) cin>>i;
    sort(a.begin(),a.end());
    for(int i=0; i<n; i++) {
        int idx=upper_bound(a.begin()+i,a.end(),abs(x-a[i]))-a.begin();
        if(idx<n && a[i]+a[idx]<=y) ans++;
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