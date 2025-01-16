#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, m, strip=0, ans=0, pass=0;
    cin>>n>>m;
    while (n--) {
        string s;
        cin>>s;
        if (strip+s.size()>m) pass=1;
        if (!pass) {
            strip+=s.size();
            ans++;
        }
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