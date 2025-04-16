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
    vector<int> v(n);
    for(int &i : v) cin>>i;
    n-=2;
    sort(v.begin(), v.end());
    for(int a : v) {
        if(n%a==0) {
            int b=*lower_bound(v.begin(), v.end(), n/a);
            if(b==n/a) {
                cout<<a<<' '<<b<<'\n';
                break;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--)
        solve();
    return 0;
}