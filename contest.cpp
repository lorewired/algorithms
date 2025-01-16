#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>>i;
    ll ans=0;
    for(int i=n-1; i>=0; i--) {
        ans+=upper_bound(a.begin(),a.begin()+i,a[i]>>1)-a.begin();
    }
    cout<<ans<<'\n';
    return 0;
}