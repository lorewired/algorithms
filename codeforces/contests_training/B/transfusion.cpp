#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    ll ods=0, evs=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if (i&1) ods+=a[i];
        else evs+=a[i];
    }
    int odc=n/2, evc=n/2;
    if(n&1) evc++;
    if (ods%odc || evs%evc || ods/odc != evs/evc) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
    }
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}