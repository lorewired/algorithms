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
    vector<int> a(n), b(n+1,0);
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        cin>>b[i];
    int diff=0;
    for (int i=0, j=1; i<n; i++, j++) {
        if (a[i]>b[j]) {
            diff+=a[i]-b[j];
        }
    }
    cout<<diff<<'\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}